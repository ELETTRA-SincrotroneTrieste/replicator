#ifndef _REPLICATORUTILS_H
#define _REPLICATORUTILS_H

#include<tango.h>

namespace Replicator_ns {

class ReplicatorUtils {
public:
    static Tango::DeviceData fromCorbaAnyToDeviceData(const CORBA::Any &in_any, Tango::CmdArgType in_type);
    static CORBA::Any* fromDeviceDataToCorbaAny(Tango::DeviceData argout, Tango::CmdArgType out_type);
};

}

#endif
