/* This file was generated by mib2c and is intended for use as a mib module
  for the ucd-snmp snmpd agent. */


#ifndef _MIBGROUP_MTETRIGGERTABLE_H
#define _MIBGROUP_MTETRIGGERTABLE_H


/* we may use header_complex from the header_complex module */


config_require(header_complex)

/* our storage structure(s) */
struct mteTriggerTable_data {


    char   *mteOwner;
    size_t  mteOwnerLen;
    char   *mteTriggerName;
    size_t  mteTriggerNameLen;
    char   *mteTriggerComment;
    size_t  mteTriggerCommentLen;
    char   *mteTriggerTest;
    size_t  mteTriggerTestLen;
    long    mteTriggerSampleType;
    oid    *mteTriggerValueID;
    size_t  mteTriggerValueIDLen;
    long    mteTriggerValueIDWildcard;
    char   *mteTriggerTargetTag;
    size_t  mteTriggerTargetTagLen;
    char   *mteTriggerContextName;
    size_t  mteTriggerContextNameLen;
    long    mteTriggerContextNameWildcard;
    unsigned long    mteTriggerFrequency;
    char   *mteTriggerObjectsOwner;
    size_t  mteTriggerObjectsOwnerLen;
    char   *mteTriggerObjects;
    size_t  mteTriggerObjectsLen;
    long    mteTriggerEnabled;
    long    mteTriggerEntryStatus;

   /* delta table */
    oid     *mteTriggerDeltaDiscontinuityID;
    size_t   mteTriggerDeltaDiscontinuityIDLen;
    long    mteTriggerDeltaDiscontinuityIDWildcard;
    long    mteTriggerDeltaDiscontinuityIDType;
    unsigned long prevDiscoTicks;
    unsigned long prevUptimeTicks;

   /* existence table */
    char   *mteTriggerExistenceTest;
    size_t  mteTriggerExistenceTestLen;
    char   *mteTriggerExistenceStartup;
    size_t  mteTriggerExistenceStartupLen;
    char   *mteTriggerExistenceObjectsOwner;
    size_t  mteTriggerExistenceObjectsOwnerLen;
    char   *mteTriggerExistenceObjects;
    size_t  mteTriggerExistenceObjectsLen;
    char   *mteTriggerExistenceEventOwner;
    size_t  mteTriggerExistenceEventOwnerLen;
    char   *mteTriggerExistenceEvent;
    size_t  mteTriggerExistenceEventLen;

   /* boolean table */
    long    mteTriggerBooleanComparison;
    long    mteTriggerBooleanValue;
    long    mteTriggerBooleanStartup;
    char   *mteTriggerBooleanObjectsOwner;
    size_t  mteTriggerBooleanObjectsOwnerLen;
    char   *mteTriggerBooleanObjects;
    size_t  mteTriggerBooleanObjectsLen;
    char   *mteTriggerBooleanEventOwner;
    size_t  mteTriggerBooleanEventOwnerLen;
    char   *mteTriggerBooleanEvent;
    size_t  mteTriggerBooleanEventLen;

   /* threshold table */
    long    mteTriggerThresholdStartup;
    long    mteTriggerThresholdRising;
    long    mteTriggerThresholdFalling;
    long    mteTriggerThresholdDeltaRising;
    long    mteTriggerThresholdDeltaFalling;
    char   *mteTriggerThresholdObjectsOwner;
    size_t  mteTriggerThresholdObjectsOwnerLen;
    char   *mteTriggerThresholdObjects;
    size_t  mteTriggerThresholdObjectsLen;
    char   *mteTriggerThresholdRisingEventOwner;
    size_t  mteTriggerThresholdRisingEventOwnerLen;
    char   *mteTriggerThresholdRisingEvent;
    size_t  mteTriggerThresholdRisingEventLen;
    char   *mteTriggerThresholdFallingEventOwner;
    size_t  mteTriggerThresholdFallingEventOwnerLen;
    char   *mteTriggerThresholdFallingEvent;
    size_t  mteTriggerThresholdFallingEventLen;
    char   *mteTriggerThresholdDeltaRisingEventOwner;
    size_t  mteTriggerThresholdDeltaRisingEventOwnerLen;
    char   *mteTriggerThresholdDeltaRisingEvent;
    size_t  mteTriggerThresholdDeltaRisingEventLen;
    char   *mteTriggerThresholdDeltaFallingEventOwner;
    size_t  mteTriggerThresholdDeltaFallingEventOwnerLen;
    char   *mteTriggerThresholdDeltaFallingEvent;
    size_t  mteTriggerThresholdDeltaFallingEventLen;

   /* internal variables */
   int storageType;
   unsigned int alarmreg;
   int lastboolresult;
   int started;
   long lastvalue;
   struct header_complex_index *hc_storage, *hc_storage_old;
   unsigned long threshold_state;

   /* pdu auth contents */
   long         have_copied_auth_info;
   long         pdu_version;
   long         pdu_securityModel;
   long         pdu_securityLevel;
   void        *pdu_transport;
   size_t       pdu_transportLen;
   oid	       *pdu_tDomain;
   size_t	pdu_tDomainLen;
   u_char      *pdu_community;
   size_t       pdu_community_len;
   char        *pdu_contextName;
   size_t       pdu_contextNameLen;
   char        *pdu_securityName;
   size_t       pdu_securityNameLen;
};

struct last_state {
   long *value;
   char lastbool;
   char lastthreshold;
};


/* enum definitions from the covered mib sections */







#define MTETRIGGERTEST_EXISTENCE                 0x80
#define MTETRIGGERTEST_BOOLEAN                   0x40
#define MTETRIGGERTEST_THRESHOLD                 0x20

#define MTETRIGGERSAMPLETYPE_ABSOLUTEVALUE       1
#define MTETRIGGERSAMPLETYPE_DELTAVALUE          2


/*  What's wrong with using the regular TruthValue definitions TV_TRUE 
    and TV_FALSE (snmp-tc.h) which are up to 77% shorter?  */

#define MTETRIGGERVALUEIDWILDCARD_TRUE           1
#define MTETRIGGERVALUEIDWILDCARD_FALSE          2



#define MTETRIGGERCONTEXTNAMEWILDCARD_TRUE       1
#define MTETRIGGERCONTEXTNAMEWILDCARD_FALSE      2




#define MTETRIGGERENABLED_TRUE                   1
#define MTETRIGGERENABLED_FALSE                  2

#define MTE_NOTSTARTED 0
#define MTE_STARTED 1

#define MTE_THRESHOLD_BEGIN  0
#define MTE_THRESHOLD_HIGH   1
#define MTE_THRESHOLD_LOW    2

/*  Just the first (MTE-specific) groups of errors defined here;
    others are numerically equal to the regular SNMP errors.  */

#define MTE_FAILURE_LOCALRESOURCELACK		-1
#define MTE_FAILURE_BADDESTINATION		-2
#define MTE_FAILURE_DESTINATIONUNREACHABLE	-3
#define MTE_FAILURE_NORESPONSE			-4
#define MTE_FAILURE_BADTYPE			-5
#define MTE_FAILURE_SAMPLEOVERRUN		-6


/* function prototypes */


void   init_mteTriggerTable(void);
FindVarMethod var_mteTriggerTable;
void parse_mteTriggerTable(const char *, char *);
void parse_simple_monitor(const char *, char *);
void parse_default_monitors(const char *, char *);
SNMPCallback store_mteTriggerTable;
netsnmp_pdu *mte_get_response(struct mteTriggerTable_data *,
                                  netsnmp_pdu *);


WriteMethod write_mteTriggerComment;
WriteMethod write_mteTriggerTest;
WriteMethod write_mteTriggerSampleType;
WriteMethod write_mteTriggerValueID;
WriteMethod write_mteTriggerValueIDWildcard;
WriteMethod write_mteTriggerTargetTag;
WriteMethod write_mteTriggerContextName;
WriteMethod write_mteTriggerContextNameWildcard;
WriteMethod write_mteTriggerFrequency;
WriteMethod write_mteTriggerObjectsOwner;
WriteMethod write_mteTriggerObjects;
WriteMethod write_mteTriggerEnabled;
WriteMethod write_mteTriggerEntryStatus;

WriteMethod write_mteTriggerEntryStatus;

void mte_enable_trigger(struct mteTriggerTable_data *item);
void mte_disable_trigger(struct mteTriggerTable_data *item);
SNMPAlarmCallback mte_run_trigger;

#endif /* _MIBGROUP_MTETRIGGERTABLE_H */
