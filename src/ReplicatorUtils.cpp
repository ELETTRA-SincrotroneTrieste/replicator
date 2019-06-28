#include <tango.h>
#include <ReplicatorUtils.h>
#include <iostream>

namespace Replicator_ns {

Tango::DeviceData ReplicatorUtils::fromCorbaAnyToDeviceData(const CORBA::Any &in_any, Tango::CmdArgType in_type) {
    Tango::DeviceData out_dData;
    switch (static_cast<long>(in_type)) {
    case 1: {
        Tango::DevBoolean var_b;
        in_any >>= CORBA::Any::to_boolean(var_b);
        out_dData << var_b;
    }
        break;

    case 22: {
        //TODO: not in the command parameter list
        //Tango::DevUChar var_uc;
        //in_any >>= CORBA::Any::to_char(var_uc);
        //out_dData << var_uc;
    }
        break;

    case 2: {
        Tango::DevShort var_s;
        in_any >>= var_s;
        out_dData << var_s;
    }
        break;

    case 6: {
        Tango::DevUShort var_us;
        in_any >>= var_us;
        out_dData << var_us;
    }
        break;

    case 3: {
        Tango::DevLong var_l;
        in_any >>= var_l;
        out_dData << var_l;
    }
        break;

    case 7: {
        Tango::DevULong var_ul;
        in_any >>= var_ul;
        out_dData << var_ul;
    }
        break;

    case 23: {
        Tango::DevLong64 var_ll;
        in_any >>= var_ll;
        out_dData << var_ll;
    }
        break;

    case 24: {
        Tango::DevULong64 var_ull;
        in_any >>= var_ull;
        out_dData << var_ull;
    }
        break;

    case 4: {
        Tango::DevFloat var_f;
        in_any >>= var_f;
        out_dData << var_f;
    }
        break;

    case 5: {
        Tango::DevDouble var_d;
        in_any >>= var_d;
        out_dData << var_d;
    }
        break;

    case 8: {
        Tango::DevString var_str;
        in_any >>= const_cast<const char *&>(var_str);
        out_dData << var_str;
    }
        break;

    case 19: {
        Tango::DevState var_sta;
        in_any >>= var_sta;
        out_dData << var_sta;
    }
        break;

    case 9: {
        Tango::DevVarCharArray* var_ca;
        in_any >>= var_ca;
        Tango::DevVarCharArray var2_ca;
        var2_ca.length(var_ca->length());
        for (unsigned int i = 0; i < var_ca->length(); i++) {
            var2_ca[i] = var_ca[0][i];
        }
        out_dData << var2_ca;
    }
        break;

    case 13: {
        Tango::DevVarDoubleArray *var_da;
        in_any >>= var_da;
        Tango::DevVarDoubleArray var2_da;
        var2_da.length(var_da->length());
        for (unsigned int i = 0; i < var_da->length(); i++) {
            var2_da[i] = var_da[0][i];
        }
        out_dData << var2_da;
        //you should not deallocate a sequence extracted from out_any
    }
        break;

    case 18: {
        Tango::DevVarDoubleStringArray* var_dsa;
        in_any >>= var_dsa;
        Tango::DevVarDoubleStringArray var2_dsa;
        var2_dsa.svalue.length(var_dsa->svalue.length());
        for (unsigned int i = 0; i < var_dsa->svalue.length(); i++) {
            var2_dsa.svalue[i] = var_dsa->svalue[i];
        }
        var2_dsa.dvalue.length(var_dsa->dvalue.length());
        for (unsigned int i = 0; i < var_dsa->dvalue.length(); i++) {
            var2_dsa.dvalue[i] = var_dsa->dvalue[i];
        }
        out_dData << var2_dsa;
    }
        break;

    case 12: {
        Tango::DevVarFloatArray* var_fa;
        in_any >>= var_fa;
        Tango::DevVarFloatArray var2_fa;
        var2_fa.length(var_fa->length());
        for (unsigned int i = 0; i < var_fa->length(); i++) {
            var2_fa[i] = var_fa[0][i];
        }
        out_dData << var2_fa;
    }
        break;

    case 11: {
        Tango::DevVarLongArray* var_la;
        in_any >>= var_la;
        Tango::DevVarLongArray var2_la;
        var2_la.length(var_la->length());
        for (unsigned int i = 0; i < var_la->length(); i++) {
            var2_la[i] = var_la[0][i];
        }
        out_dData << var2_la;
    }
        break;

    case 17: {
        Tango::DevVarLongStringArray* var_lsa;
        in_any >>= var_lsa;
        Tango::DevVarLongStringArray var2_lsa;
        var2_lsa.svalue.length(var_lsa->svalue.length());
        for (unsigned int i = 0; i < var_lsa->svalue.length(); i++) {
            var2_lsa.svalue[i] = var_lsa->svalue[i];
        }
        var2_lsa.lvalue.length(var_lsa->lvalue.length());
        for (unsigned int i = 0; i < var_lsa->lvalue.length(); i++) {
            var2_lsa.lvalue[i] = var_lsa->lvalue[i];
        }
        out_dData << var2_lsa;
    }
        break;

    case 10: {
        Tango::DevVarShortArray* var_sa;
        in_any >>= var_sa;
        Tango::DevVarShortArray var2_sa;
        var2_sa.length(var_sa->length());
        for (unsigned int i = 0; i < var_sa->length(); i++) {
            var2_sa[i] = var_sa[0][i];
        }
        out_dData << var2_sa;
    }
        break;

    case 16: {
        Tango::DevVarStringArray* var_stra;
        in_any >>= var_stra;
        Tango::DevVarStringArray var2_stra;
        var2_stra.length(var_stra->length());
        for (unsigned int i = 0; i < var_stra->length(); i++) {
            var2_stra[i] = var_stra[0][i];
        }
        out_dData << var2_stra;
    }
        break;

    case 15: {
        Tango::DevVarULongArray* var_ula;
        in_any >>= var_ula;
        Tango::DevVarULongArray var2_ula;
        var2_ula.length(var_ula->length());
        for (unsigned int i = 0; i < var_ula->length(); i++) {
            var2_ula[i] = var_ula[0][i];
        }
        out_dData << var2_ula;
    }
        break;

    case 14: {
        Tango::DevVarUShortArray* var_usa;
        in_any >>= var_usa;
        Tango::DevVarUShortArray var2_usa;
        var2_usa.length(var_usa->length());
        for (unsigned int i = 0; i < var_usa->length(); i++) {
            var2_usa[i] = var_usa[0][i];
        }
        out_dData << var2_usa;
    }
        break;

    case 20: {
        //TODO:da testare, se funziona si usa direttamente lo string
        Tango::DevString var_str;
        in_any >>= const_cast<const char *&>(var_str);
        out_dData << var_str;
    }
        break;

    case 21: {
        //TODO: da testare
        //Tango::DevVarBooleanArray* var_usa;
        //in_any >>= var_usa;
        //Tango::DevVarBooleanArray var2_usa;
        //var2_usa.length(var_usa->length());
        //for(unsigned int i=0; i< var_usa->length();i++)
        //{
        //	var2_usa[i] = var_usa[0][i];
        //}
        //out_dData << &var2_usa;
    }
        break;

    case 25: {
        //TODO: da testare
        Tango::DevVarLong64Array* var_usa;
        in_any >>= var_usa;
        Tango::DevVarLong64Array var2_usa;
        var2_usa.length(var_usa->length());
        for (unsigned int i = 0; i < var_usa->length(); i++) {
            var2_usa[i] = var_usa[0][i];
        }
        out_dData << var2_usa;
    }
        break;

    case 26: {
        //TODO: da testare
        Tango::DevVarULong64Array* var_usa;
        in_any >>= var_usa;
        Tango::DevVarULong64Array var2_usa;
        var2_usa.length(var_usa->length());
        for (unsigned int i = 0; i < var_usa->length(); i++) {
            var2_usa[i] = var_usa[0][i];
        }
        out_dData << var2_usa;
    }
        break;
    }

    return out_dData;

}

CORBA::Any*
ReplicatorUtils::fromDeviceDataToCorbaAny(Tango::DeviceData in_dData, Tango::CmdArgType out_type) {

    CORBA::Any* out_any = new CORBA::Any();

    switch (static_cast<long>(out_type)) {
    case 1: {
        Tango::DevBoolean var_b;
        in_dData >> var_b;
        *out_any <<= CORBA::Any::from_boolean(var_b);
    }
        break;

    case 22: {
        //TODO:uchar
    }
        break;

    case 2: {
        Tango::DevShort var_s;
        in_dData >> var_s;
        *out_any <<= var_s;
    }
        break;

    case 6: {
        Tango::DevUShort var_us;
        in_dData >> var_us;
        *out_any <<= var_us;
    }
        break;

    case 3: {
        Tango::DevLong var_l;
        in_dData >> var_l;
        *out_any <<= var_l;
    }
        break;

    case 7: {
        Tango::DevULong var_ul;
        in_dData >> var_ul;
        *out_any <<= var_ul;
    }
        break;

    case 23: {
        Tango::DevLong64 var_ll;
        in_dData >> var_ll;
        *out_any <<= var_ll;
    }
        break;

    case 24: {
        Tango::DevULong64 var_ull;
        in_dData >> var_ull;
        *out_any <<= var_ull;
    }
        break;

    case 4: {
        Tango::DevFloat var_f;
        in_dData >> var_f;
        *out_any <<= var_f;
    }
        break;

    case 5: {
        Tango::DevDouble var_d;
        in_dData >> var_d;
        *out_any <<= var_d;
    }
        break;

    case 8: {
        Tango::DevString var_str;
        in_dData >> const_cast<const char *&>(var_str);
        *out_any <<= var_str;
    }
        break;

    case 19: {
        Tango::DevState var_sta;
        in_dData >> var_sta;
        *out_any <<= var_sta;
    }
        break;

    case 9: {
        const Tango::DevVarCharArray* var_ca;
        in_dData >> var_ca;
        *out_any <<= *var_ca;
    }
        break;

    case 13: {
        const Tango::DevVarDoubleArray* var_da;
        in_dData >> var_da;
        *out_any <<= *var_da;
    }
        break;

    case 18: {
        const Tango::DevVarDoubleStringArray* var_dsa;
        in_dData >> var_dsa;
        *out_any <<= *var_dsa;
    }
        break;

    case 12: {
        const Tango::DevVarFloatArray* var_fa;
        in_dData >> var_fa;
        *out_any <<= *var_fa;
    }
        break;

    case 11: {
        const Tango::DevVarLongArray* var_la;
        in_dData >> var_la;
        *out_any <<= *var_la;
    }
        break;

    case 17: {
        const Tango::DevVarLongStringArray* var_lsa;
        in_dData >> var_lsa;
        *out_any <<= *var_lsa;
    }
        break;

    case 10: {
        const Tango::DevVarShortArray* var_sa;
        in_dData >> var_sa;
        *out_any <<= *var_sa;
    }
        break;

    case 16: {
        const Tango::DevVarStringArray* var_stra;
        in_dData >> var_stra;
        *out_any <<= *var_stra;
    }
        break;

    case 15: {
        const Tango::DevVarULongArray* var_ula;
        in_dData >> var_ula;
        *out_any <<= *var_ula;
    }
        break;

    case 14: {
        const Tango::DevVarUShortArray* var_usa;
        in_dData >> var_usa;
        *out_any <<= *var_usa;
    }
        break;

    case 20: {
        //TODO: da testare
        Tango::DevString var_str;
        in_dData >> const_cast<const char *&>(var_str);
        *out_any <<= var_str;
    }
        break;

    case 21: {
        //TODO: da implementare
    }
        break;

    case 25: {
        //TODO: da testare
        const Tango::DevVarLong64Array* var_ula;
        in_dData >> var_ula;
        *out_any <<= *var_ula;
    }
        break;

    case 26: {
        //TODO: da testare
        const Tango::DevVarULong64Array* var_ula;
        in_dData >> var_ula;
        *out_any <<= *var_ula;
    }
        break;
    }

    return out_any;
}

}
