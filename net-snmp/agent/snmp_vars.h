/*
 * Definitions for SNMP (RFC 1067) agent variable finder.
 *
 */

#ifndef _SNMP_VARS_H_
#define _SNMP_VARS_H_

/***********************************************************
	Copyright 1988, 1989 by Carnegie Mellon University
	Copyright 1989	TGV, Incorporated

		      All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of CMU and TGV not be used
in advertising or publicity pertaining to distribution of the software
without specific, written prior permission.

CMU AND TGV DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
EVENT SHALL CMU OR TGV BE LIABLE FOR ANY SPECIAL, INDIRECT OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.
******************************************************************/

struct variable;

/* Function pointer called by the master agent for writes. */
typedef int (WriteMethod)(int action,
        u_char  *var_val,
        u_char   var_val_type,
        size_t   var_val_len,
        u_char  *statP,
        oid     *name,
        size_t   length);

/* Function pointer called by the master agent for mib information retrieval */
typedef u_char *(FindVarMethod)(struct variable *vp,
        oid     *name,
        size_t  *length,
        int      exact,
        size_t  *var_len,
        WriteMethod   **write_method);

/* Function pointer called by the master agent for setting up subagent requests */
struct agent_snmp_session; 
typedef int (AddVarMethod)(struct agent_snmp_session *asp,
        struct variable_list     *vbp);

struct nlist;

extern long long_return;
extern u_char return_buf[];

extern oid nullOid[];
extern int nullOidLen;

#define INST	0xFFFFFFFF	/* used to fill out the instance field of the variables table */

struct variable {
    u_char	    magic;	    /* passed to function as a hint */
    char	    type;	    /* type of variable */
/* See important comment in snmp_vars.c relating to acl */
    u_short	    acl;	    /* access control list for variable */
    FindVarMethod *findVar;  /* function that finds variable */
    u_char	    namelen;	    /* length of above */
    oid		    name[MAX_OID_LEN];	    /* object identifier of variable */
};

int subtree_old_size (void);
void sort_tree (void);
struct subtree *find_subtree (oid *, size_t, struct subtree *);
struct subtree *find_subtree_next (oid *, size_t, struct subtree *);
struct subtree *find_subtree_previous (oid *, size_t, struct subtree *);
int register_mib (const char *, struct variable *, size_t , size_t , oid *, size_t);
int unregister_mib (oid *, size_t);
struct subtree *free_subtree (struct subtree *);
void init_agent(void);
int compare_tree (oid *, size_t, oid *, size_t);
int in_a_view(oid *, size_t *, struct snmp_pdu *, int);

/* REGISTER_MIB(): This macro simply loads register_mib with less pain:

   descr:   A short description of the mib group being loaded.
   var:     The variable structure to load.
   vartype: The variable structure used to define it (variable2, variable4, ...)
   theoid:  A *initialized* *exact length* oid pointer.
            (sizeof(theoid) *must* return the number of elements!) 
*/
#define REGISTER_MIB(descr, var, vartype, theoid)                      \
  (void)register_mib(descr, (struct variable *) var, sizeof(struct vartype), \
               sizeof(var)/sizeof(struct vartype),                     \
               theoid, sizeof(theoid)/sizeof(oid));


/* fail overloads non-negative integer value. it must be -1 ! */
#define MATCH_FAILED	(-1)
#define MATCH_SUCCEEDED	0

#endif /* _SNMP_VARS_H_ */
