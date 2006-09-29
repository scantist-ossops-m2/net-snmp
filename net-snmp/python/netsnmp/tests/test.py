""" Runs all unit tests for the netsnmp package.   """
# Copyright (c) 2006 Andy Gross.  See LICENSE.txt for details.

import sys
import unittest
import netsnmp

class BasicTests(unittest.TestCase):
    def testFuncs(self):        
        print ""
        var = netsnmp.Varbind('sysDescr.0')
        var = netsnmp.Varbind('sysDescr','0')
        var = netsnmp.Varbind(
            '.iso.org.dod.internet.mgmt.mib-2.system.sysDescr','0')
        var = netsnmp.Varbind(
            '.iso.org.dod.internet.mgmt.mib-2.system.sysDescr.0')
        var = netsnmp.Varbind('.1.3.6.1.2.1.1.1.0')

        var = netsnmp.Varbind('.1.3.6.1.2.1.1.1','0')

        print "----------------------------------------\n"
        res = netsnmp.snmpget(var,
                              Version = 1,
                              DestHost='localhost',
                              Community='public')

        print "v1 snmpget result: ", res, "\n"

        print "v1 get var: ",  var.tag, var.iid, "=", var.val, '(',var.type,')'
        
        print "----------------------------------------\n"
        res = netsnmp.snmpgetnext(var,
                                  Version = 1,
                                  DestHost='localhost',
                                  Community='public')

        print "v1 snmpgetnext result: ", res, "\n"
                
        print "v1 getnext var: ",  var.tag, var.iid, "=", var.val, '(',var.type,')'
        
        print "----------------------------------------\n"
        var = netsnmp.Varbind('sysLocation','0', 'my new location')
        res = netsnmp.snmpset(var,
                        Version = 1,
                        DestHost='localhost',
                        Community='public')

        print "v1 snmpset result: ", res, "\n"

        print "v1 set var: ",  var.tag, var.iid, "=", var.val, '(',var.type,')'
        
        print "----------------------------------------\n"
        vars = netsnmp.VarList(netsnmp.Varbind('system'))

        print "v1 varlist walk in: "
        for var in vars:
            print "  ",var.tag, var.iid, "=", var.val, '(',var.type,')'

        res = netsnmp.snmpwalk(vars,
                               Version = 1,
                               DestHost='localhost',
                               Community='public')
        print "v1 snmpwalk result: ", res, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
       
        
        print "----------------------------------------\n"

        print "v1 varbind walk in: "
        var = netsnmp.Varbind('system')
        res = netsnmp.snmpwalk(var,
                               Version = 1,
                               DestHost='localhost',
                               Community='public')
        print "v1 snmpwalk result (should be = orig): ", res, "\n"

        print var.tag, var.iid, "=", var.val, '(',var.type,')'
        
        print "----------------------------------------\n"
        sess = netsnmp.Session(Version=1,
                               DestHost='localhost',
                               Community='public')
        
        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime', 0),
                               netsnmp.Varbind('sysContact', 0),
                               netsnmp.Varbind('sysLocation', 0))
        vals = sess.get(vars)
        print "v1 sess.get result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
       
        vals = sess.getnext(vars)
        print "v1 sess.getnext result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
       
        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime'),
                               netsnmp.Varbind('sysORLastChange'),
                               netsnmp.Varbind('sysORID'),
                               netsnmp.Varbind('sysORDescr'),
                               netsnmp.Varbind('sysORUpTime'))

        vals = sess.getbulk(2, 8, vars)
        print "v1 sess.getbulk result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'

        print "----------------------------------------\n"

        vars = netsnmp.VarList(
            netsnmp.Varbind('sysLocation', '0', 'my newer location'))
        res = sess.set(vars)
        print "v1 sess.set result: ", res, "\n"

        print "----------------------------------------\n"
        vars = netsnmp.VarList(netsnmp.Varbind('system'))
                
        vals = sess.walk(vars)
        print "v1 sess.walk result: ", vals, "\n"
        
        for var in vars:
            print "  ",var.tag, var.iid, "=", var.val, '(',var.type,')'
            
        print "----------------------------------------\n"

        sess = netsnmp.Session(Version=2,
                               DestHost='localhost',
                               Community='public')

        sess.UseEnums = 1
        sess.UseLongNames = 1
        
        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime', 0),
                               netsnmp.Varbind('sysContact', 0),
                               netsnmp.Varbind('sysLocation', 0))
        vals = sess.get(vars)
        print "v2 sess.get result: ", vals, "\n"

        print "----------------------------------------\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"
       
        vals = sess.getnext(vars)
        print "v2 sess.getnext result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"
       
        print "----------------------------------------\n"

        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime'),
                               netsnmp.Varbind('sysORLastChange'),
                               netsnmp.Varbind('sysORID'),
                               netsnmp.Varbind('sysORDescr'),
                               netsnmp.Varbind('sysORUpTime'))

        vals = sess.getbulk(2, 8, vars)
        print "v2 sess.getbulk result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"

        print "----------------------------------------\n"

        vars = netsnmp.VarList(
            netsnmp.Varbind('sysLocation','0','my even newer location'))
        
        res = sess.set(vars)
        print "v2 sess.set result: ", res, "\n"

        print "----------------------------------------\n"
        vars = netsnmp.VarList(netsnmp.Varbind('system'))
                
        vals = sess.walk(vars)
        print "v2 sess.walk result: ", vals, "\n"
        
        for var in vars:
            print "  ",var.tag, var.iid, "=", var.val, '(',var.type,')'
            
        print "----------------------------------------\n"
        sess = netsnmp.Session(Version=3,
                               DestHost='localhost',
                               SecLevel='authPriv',
                               SecName='initial',
                               PrivPass='priv_pass',
                               AuthPass='auth_pass')

        sess.UseSprintValue = 1

        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime', 0),
                               netsnmp.Varbind('sysContact', 0),
                               netsnmp.Varbind('sysLocation', 0))
        print "----------------------------------------\n"
        vals = sess.get(vars)
        print "v3 sess.get result: ", vals, "\n"
        
        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"

        print "----------------------------------------\n"
       
        vals = sess.getnext(vars)
        print "v3 sess.getnext result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"
       
        vars = netsnmp.VarList(netsnmp.Varbind('sysUpTime'),
                               netsnmp.Varbind('sysORLastChange'),
                               netsnmp.Varbind('sysORID'),
                               netsnmp.Varbind('sysORDescr'),
                               netsnmp.Varbind('sysORUpTime'))

        vals = sess.getbulk(2, 8, vars)
        print "v3 sess.getbulk result: ", vals, "\n"

        for var in vars:
            print var.tag, var.iid, "=", var.val, '(',var.type,')'
        print "\n"

        print "----------------------------------------\n"

        vars = netsnmp.VarList(
            netsnmp.Varbind('sysLocation','0', 'my final destination'))
        res = sess.set(vars)
        print "v3 sess.set result: ", res, "\n"
        
        print "----------------------------------------\n"
        vars = netsnmp.VarList(netsnmp.Varbind('system'))
                
        vals = sess.walk(vars)
        print "v3 sess.walk result: ", vals, "\n"
        
        for var in vars:
            print "  ",var.tag, var.iid, "=", var.val, '(',var.type,')'
            

if __name__=='__main__':
    unittest.main()
