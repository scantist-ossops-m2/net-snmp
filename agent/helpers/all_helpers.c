/** @name handler
 *  @{ */

#include <net-snmp/net-snmp-config.h>

#ifdef STILL_TO_DO
	/*
	 * It ought to be possible to just #include these files,
	 *   but they rely on various other types being defined first.
	 *
	 * I really can't face tracking down the dependency chain
	 *   just at the moment.
	 * So we'll just have to live with the warnings....
	 */
#include <net-snmp/agent/debug_handler.h>
#include <net-snmp/agent/serialize.h>
#include <net-snmp/agent/read_only.h>
#include <net-snmp/agent/bulk_to_next.h>
#endif

/** call the initialization sequence for all handlers with init_ routines. */
void
netsnmp_init_helpers(void) 
{
    init_netsnmp_debug_helper();
    netsnmp_init_serialize();
    init_netsnmp_read_only_helper();
    init_netsnmp_bulk_to_next_helper();
}

/** @} */
