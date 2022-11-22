#ifndef ODDL_H
#define ODDL_H

#ifdef __cplusplus
extern "C" {
#endif

#define ODDL_VERSION_MAJOR 0
#define ODDL_VERSION_MINOR 1
#define ODDL_VERSION_PATCH 0

#include <stddef.h>
#include <stdint.h>

#ifndef ODDL_TRUE
#define ODDL_TRUE 1
#endif
#ifndef ODDL_FALSE
#define ODDL_FALSE 0
#endif

#ifndef ODDL_BOOL_T
#define ODDL_BOOL_T int
#endif

#ifndef ODDL_NULL
#define ODDL_NULL 0
#endif

#ifndef ODDL_HALF_T
#define ODDL_HALF_T float
#endif

enum ODDLStructType {
    ODDLStructTypeRoot,
    ODDLStructTypeDerived,
    ODDLStructTypePrimitive
};
enum ODDLDataType {
    ODDLDataTypeInvalid = 0,
    ODDLDataTypeBool,
    ODDLDataTypeInt8,
    ODDLDataTypeInt16,
    ODDLDataTypeInt32,
    ODDLDataTypeInt64,
    ODDLDataTypeUInt8,
    ODDLDataTypeUInt16,
    ODDLDataTypeUInt32,
    ODDLDataTypeUInt64,
    ODDLDataTypeHalf,
    ODDLDataTypeFloat,
    ODDLDataTypeDouble,
    ODDLDataTypeString,
    ODDLDataTypeRef,
    ODDLDataTypeType,
    ODDLDataTypeBase64
};
enum ODDLError {
    ODDLErrorUnknown,
    ODDLErrorUnexpectedToken,
    ODDLErrorInvalidType,
    ODDLErrorOutOfMemory,
    ODDLErrorOutOfRange,
    ODDLErrorUnexpectedEndOfFile,
    ODDLErrorInvalidIdentifier,
    ODDLErrorUnexpectedEndOfToken,
    ODDLErrorInvalidData
};

struct ODDLProp;
struct ODDL;

enum ODDLError ODDL_getError();
char const* ODDL_getErrorString();

struct ODDL* ODDL_create();
struct ODDL* ODDL_parseFromString(char const* ddlStr);
void ODDL_free(struct ODDL* ddl);

char const* ODDL_getPropIdentifier(struct ODDLProp* prop);
struct ODDLProp* ODDL_getPropNext(struct ODDLProp* prop);

ODDL_BOOL_T ODDL_getPropBoolValue(struct ODDLProp* prop, ODDL_BOOL_T* outVal);
ODDL_BOOL_T ODDL_getPropInt8Value(struct ODDLProp* prop, int8_t* outVal);
ODDL_BOOL_T ODDL_getPropInt16Value(struct ODDLProp* prop, int16_t* outVal);
ODDL_BOOL_T ODDL_getPropInt32Value(struct ODDLProp* prop, int32_t* outVal);
ODDL_BOOL_T ODDL_getPropInt64Value(struct ODDLProp* prop, int64_t* outVal);
ODDL_BOOL_T ODDL_getPropUInt8Value(struct ODDLProp* prop, uint8_t* outVal);
ODDL_BOOL_T ODDL_getPropUInt16Value(struct ODDLProp* prop, uint16_t* outVal);
ODDL_BOOL_T ODDL_getPropUInt32Value(struct ODDLProp* prop, uint32_t* outVal);
ODDL_BOOL_T ODDL_getPropUInt64Value(struct ODDLProp* prop, uint64_t* outVal);
ODDL_BOOL_T ODDL_getPropHalfValue(struct ODDLProp* prop, ODDL_HALF_T* outVal);
ODDL_BOOL_T ODDL_getPropFloatValue(struct ODDLProp* prop, float* outVal);
ODDL_BOOL_T ODDL_getPropDoubleValue(struct ODDLProp* prop, double* outVal);
ODDL_BOOL_T ODDL_getPropStringValue(struct ODDLProp* prop, char const** outVal);
ODDL_BOOL_T ODDL_getPropRefValue(struct ODDLProp* prop, struct ODDL** outVal);
ODDL_BOOL_T ODDL_getPropTypeValue(struct ODDLProp* prop, enum ODDLDataType* outVal);
ODDL_BOOL_T ODDL_getPropBase64Value(struct ODDLProp* prop, void const** outVal, int* outSize);

enum ODDLStructType ODDL_getStructType(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructRoot(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDerived(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructPrimitive(struct ODDL* struc);

char const* ODDL_getStructIdentifier(struct ODDL* struc);
ODDL_BOOL_T ODDL_hasStructName(struct ODDL* struc);
char const* ODDL_getStructName(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructNameGlobal(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructNameLocal(struct ODDL* struc);

int ODDL_getStructPropCount(struct ODDL* struc);
struct ODDLProp* ODDL_getStructPropStart(struct ODDL* struc);
struct ODDLProp* ODDL_getStructPropByIndex(struct ODDL* struc, int index);
struct ODDLProp* ODDL_findStructProp(struct ODDL* struc, char const* propIdentifier);

struct ODDL* ODDL_getStructSiblingNext(struct ODDL* struc);
struct ODDL* ODDL_getStructSiblingNextByIdentifier(struct ODDL* struc, char const* id);

int ODDL_getStructSubCount(struct ODDL* struc);
struct ODDL* ODDL_getStructSubStart(struct ODDL* struc);
struct ODDL* ODDL_getStructSubByIndex(struct ODDL* struc, int index);
struct ODDL* ODDL_findStructSubByName(struct ODDL* struc, char const* name);
struct ODDL* ODDL_findStructSubByIdentifier(struct ODDL* struc, char const* id);

ODDL_BOOL_T ODDL_isStructDataFlat(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataArray(struct ODDL* struc);
int ODDL_getStructDataArraySize(struct ODDL* struc);
ODDL_BOOL_T ODDL_hasStructDataStates(struct ODDL* struc);
int ODDL_getStructDataCount(struct ODDL* struc);
struct ODDLData* ODDL_getStructDataStart(struct ODDL* struc);
struct ODDLData* ODDL_getStructDataByIndex(struct ODDL* struc, int index);

enum ODDLDataType ODDL_getStructDataType(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataBool(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataInt8(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataInt16(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataInt32(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataInt64(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataUInt8(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataUInt16(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataUInt32(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataUInt64(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataHalf(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataFloat(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataDouble(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataString(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataRef(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataType(struct ODDL* struc);
ODDL_BOOL_T ODDL_isStructDataBase64(struct ODDL* struc);

ODDL_BOOL_T ODDL_getDataBoolValue(struct ODDLData* data, ODDL_BOOL_T* outVal);
ODDL_BOOL_T ODDL_getDataBoolArrayValue(struct ODDLData* data, ODDL_BOOL_T* outVal, int count);
ODDL_BOOL_T ODDL_getDataInt8Value(struct ODDLData* data, int8_t* outVal);
ODDL_BOOL_T ODDL_getDataInt8ArrayValue(struct ODDLData* data, int8_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataInt16Value(struct ODDLData* data, int16_t* outVal);
ODDL_BOOL_T ODDL_getDataInt16ArrayValue(struct ODDLData* data, int16_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataInt32Value(struct ODDLData* data, int32_t* outVal);
ODDL_BOOL_T ODDL_getDataInt32ArrayValue(struct ODDLData* data, int32_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataInt64Value(struct ODDLData* data, int64_t* outVal);
ODDL_BOOL_T ODDL_getDataInt64ArrayValue(struct ODDLData* data, int64_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataUInt8Value(struct ODDLData* data, uint8_t* outVal);
ODDL_BOOL_T ODDL_getDataUInt8ArrayValue(struct ODDLData* data, uint8_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataUInt16Value(struct ODDLData* data, uint16_t* outVal);
ODDL_BOOL_T ODDL_getDataUInt16ArrayValue(struct ODDLData* data, uint16_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataUInt32Value(struct ODDLData* data, uint32_t* outVal);
ODDL_BOOL_T ODDL_getDataUInt32ArrayValue(struct ODDLData* data, uint32_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataUInt64Value(struct ODDLData* data, uint64_t* outVal);
ODDL_BOOL_T ODDL_getDataUInt64ArrayValue(struct ODDLData* data, uint64_t* outVal, int count);
ODDL_BOOL_T ODDL_getDataHalfValue(struct ODDLData* data, ODDL_HALF_T* outVal);
ODDL_BOOL_T ODDL_getDataHalfArrayValue(struct ODDLData* data, ODDL_HALF_T* outVal, int count);
ODDL_BOOL_T ODDL_getDataFloatValue(struct ODDLData* data, float* outVal);
ODDL_BOOL_T ODDL_getDataFloatArrayValue(struct ODDLData* data, float* outVal, int count);
ODDL_BOOL_T ODDL_getDataDoubleValue(struct ODDLData* data, double* outVal);
ODDL_BOOL_T ODDL_getDataDoubleArrayValue(struct ODDLData* data, double* outVal, int count);
ODDL_BOOL_T ODDL_getDataStringValue(struct ODDLData* data, char const** outVal);
ODDL_BOOL_T ODDL_getDataStringArrayValue(struct ODDLData* data, char const** outVal, int count);
ODDL_BOOL_T ODDL_getDataRefValue(struct ODDLData* data, struct ODDL** outVal);
ODDL_BOOL_T ODDL_getDataRefArrayValue(struct ODDLData* data, struct ODDL** outVal, int count);
ODDL_BOOL_T ODDL_getDataTypeValue(struct ODDLData* data, enum ODDLDataType* outVal);
ODDL_BOOL_T ODDL_getDataTypeArrayValue(struct ODDLData* data, enum ODDLDataType* outVal, int count);
ODDL_BOOL_T ODDL_getDataBase64Value(struct ODDLData* data, void const** outVal, int* outSize);
ODDL_BOOL_T ODDL_getDataBase64ArrayValue(struct ODDLData* data, void const** outVal, int* outSizes, int count);

struct ODDLData* ODDL_getDataNext(struct ODDLData* data);
struct ODDLData* ODDL_getDataNextByIdentifier(struct ODDLData* data, char const* identifier);

// #define ODDL_IMPLEMENTATION
#ifdef ODDL_IMPLEMENTATION

#include <stdlib.h>
#include <string.h>

#ifndef ODDL_CUSTOM_MATH
#include <math.h>
#define ODDL_DPOW(num, exp) pow((num), (exp))
#endif

enum ODDLPropStorageType {
    ODDLPropStorageTypeInvalid,
    ODDLPropStorageTypeRawString,
    ODDLPropStorageTypeString,
    ODDLPropStorageTypeRef,
    ODDLPropStorageTypeType,
    ODDLPropStorageTypeBase64
};

struct ODDLProp {
    char* identifier;
    enum ODDLPropStorageType storageType;
    char* value;
    size_t size;

    struct ODDLProp* next;
};

struct ODDLData {
    enum ODDLDataType type;
    char* identifier;
    int size;
    void* data;
    struct ODDLData* next;
};

struct ODDLBase64Data {
    int size;
    void* data;
};

struct ODDL {
    enum ODDLStructType type;
    char* identifier;
    char* name;
    ODDL_BOOL_T isNameGlobal;
    int dataArrayCount;
    enum ODDLDataType dataType;
    ODDL_BOOL_T isDataStates;
    
    int propCount;
    struct ODDLProp* propStart;
    int subCount;
    struct ODDL* subStart;
    int dataCount;
    struct ODDLData* dataStart;

    struct ODDL* next;
};

static enum ODDLError global_error;
static char const* global_error_str;
enum ODDLError ODDL_getError() {
    return global_error;
}
char const* ODDL_getErrorString() {
    return global_error_str;
}

void ODDL_reportError(enum ODDLError error) {
    global_error = error;
    switch(global_error) {
    case ODDLErrorUnexpectedToken:
        global_error_str = "Unexpected token.";
        break;
    case ODDLErrorInvalidType:
        global_error_str = "Unknown type.";
        break;
    case ODDLErrorOutOfMemory:
        global_error_str = "Out of memory.";
        break;
    case ODDLErrorOutOfRange:
        global_error_str = "Out of range.";
        break;
    case ODDLErrorUnexpectedEndOfFile:
        global_error_str = "Out of range.";
        break;
    case ODDLErrorInvalidIdentifier:
        global_error_str = "Invalid identifier.";
        break;
    case ODDLErrorInvalidData:
        global_error_str = "Invalid data.";
        break;
    default:
        global_error_str = "Unknown.";
        break;
    }
}

uint32_t ODDL_convertHalfBitsToFloatBits(uint16_t halfBits) {
    // Source:
    //  - J. van der Zijp, “Fast Half Float Conversions,” Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].

    uint32_t h = (uint32_t)halfBits;

    static uint32_t mantissatable[2028];
    static uint32_t offsettable[64];
    static uint32_t exponenttable[64];
    static ODDL_BOOL_T init = ODDL_FALSE;
    if(!init) {
        init = ODDL_TRUE;

        mantissatable[0] = 0;
        for(int i = 1; i <= 1023; i++) {
            uint32_t m = i << 13;
            uint32_t e = 0;
            while(!(m & 0x00800000)) {
                e -= 0x00800000;
                m <<= 1;
            }
            m &= ~0x00800000;
            e += 0x38800000;
            mantissatable[i] = m | e;
        }
        for(int i = 1024; i <= 2047; i++) {
            mantissatable[i] = 0x38000000 + ((i - 1024) << 13);
        }
        
        exponenttable[0] = 0;
        exponenttable[32] = 0x80000000;
        for(int i = 1; i <= 30; i++) {
            exponenttable[i] = i << 23;
        }
        for(int i = 33; i <= 62; i++) {
            exponenttable[i] = 0x80000000 + ((i - 32) << 23);
        }
        exponenttable[31] = 0x47800000;
        exponenttable[63] = 0xC7800000;

        for(int i = 0; i < 64; i++) {
            if(i == 0 || i == 32) {
                offsettable[i] = 0;
                continue;
            }
            offsettable[i] = 1024;
        }
    }

    return mantissatable[offsettable[h >> 10] + (h & 0x3FF)] + exponenttable[h >> 10];
}
uint16_t ODDL_convertFloatBitsToHalfBits(uint32_t floatBits) {
    // Source:
    //  - J. van der Zijp, “Fast Half Float Conversions,” Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].
    static uint16_t basetable[512];
    static uint8_t shifttable[512];
    static ODDL_BOOL_T init = ODDL_FALSE;
    if(!init) {
        init = ODDL_TRUE;

        for(int i = 0; i < 256; i++) {
            int e = i - 127;
            if(e < -24) {
                basetable[i | 0x000] = 0x0000;
                basetable[i | 0x100] = 0x8000;
                shifttable[i | 0x000] = 24;
                shifttable[i | 0x100] = 24;
            } else if(e < -14) {
                basetable[i | 0x000] = (0x0400 >> (-e - 14));
                basetable[i | 0x100] = (0x8000 >> (-e - 14) | 0x8000);
                shifttable[i | 0x000] = -e - 1;
                shifttable[i | 0x100] = -e - 1;
            } else if(e <= 15) {
                basetable[i | 0x000] = ((e + 15) << 10);
                basetable[i | 0x100] = ((e + 15) << 10) | 0x8000;
                shifttable[i | 0x000] = 13;
                shifttable[i | 0x100] = 13;
            } else if(e < 128) {
                basetable[i | 0x000] = 0x7C00;
                basetable[i | 0x100] = 0xFC00;
                shifttable[i | 0x000] = 24;
                shifttable[i | 0x100] = 24;
            } else {
                basetable[i | 0x000] = 0x7C00;
                basetable[i | 0x100] = 0xFC00;
                shifttable[i | 0x000] = 13;
                shifttable[i | 0x100] = 13;
            }
        }
    }

    return basetable[(floatBits >> 23) & 0x1FF] + ((floatBits * 0x007FFFFF) >> shifttable[(floatBits >> 23) & 0x1FF]);
}

struct ODDL ODDL_createStruct(enum ODDLStructType structType) {
    return (struct ODDL) {
        .type = structType,
        .identifier = ODDL_NULL,
        .name = ODDL_NULL,
        .isNameGlobal = ODDL_FALSE,
        .dataArrayCount = 0,
        .dataType = ODDLDataTypeInvalid,
        .isDataStates = ODDL_FALSE,

        .propCount = 0,
        .propStart = ODDL_NULL,
        .subCount = 0,
        .subStart = ODDL_NULL,
        .dataCount = 0,
        .dataStart = ODDL_NULL,

        .next = ODDL_NULL
    };
}
struct ODDL ODDL_createRoot() {
    return ODDL_createStruct(ODDLStructTypeRoot);
}

struct ODDLProp ODDL_createProp() {
    return (struct ODDLProp) {
        .identifier = ODDL_NULL,
        .storageType = ODDLPropStorageTypeInvalid,
        .value = ODDL_NULL,
        .size = 0,
        .next = ODDL_NULL
    };
}

struct ODDLData ODDL_createData(enum ODDLDataType type) {
    return (struct ODDLData) {
        .type = type
    };
}

struct ODDL* ODDL_create() {
    // Init if needed
    ODDL_convertHalfBitsToFloatBits(0);
    ODDL_convertFloatBitsToHalfBits(0);

    struct ODDL* root = (struct ODDL*)malloc(sizeof(struct ODDL));
    if(root == ODDL_NULL) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return ODDL_NULL;
    }
    *root = ODDL_createRoot();
    return root;
}

void ODDL_freeProp(struct ODDLProp* prop) {
    if(prop == ODDL_NULL) {
        return;
    }

    if(prop->identifier != ODDL_NULL) {
        free(prop->identifier);
    }
    if(prop->value != ODDL_NULL) {
        free(prop->value);
    }
    ODDL_freeProp(prop->next);
    free(prop);
}
void ODDL_freeData(struct ODDLData* data) {
    if(data == ODDL_NULL) {
        return;
    }

    if(data->identifier != ODDL_NULL) {
        free(data->identifier);
    }
    if(data->data != ODDL_NULL) {
        free(data->data);
    }
    ODDL_freeData(data->next);
    free(data);
}
void ODDL_free(struct ODDL* ddl) {
    if(ddl == ODDL_NULL) {
        return;
    }

    if(ddl->identifier != ODDL_NULL) {
        free(ddl->identifier);
    }
    if(ddl->name != ODDL_NULL) {
        free(ddl->name);
    }
    ODDL_freeProp(ddl->propStart);
    ODDL_freeData(ddl->dataStart);
    ODDL_free(ddl->subStart);
    ODDL_free(ddl->next);
    free(ddl);
}

ODDL_BOOL_T ODDL_isIdentifierDataType(char const* identifier, int len) {
    if(len < 0) {
        len = strlen(identifier);
    }
    return strncmp(identifier, "bool", len) == 0
        || strncmp(identifier, "b", len) == 0
        || strncmp(identifier, "int8", len) == 0
        || strncmp(identifier, "i8", len) == 0
        || strncmp(identifier, "int16", len) == 0
        || strncmp(identifier, "i16", len) == 0
        || strncmp(identifier, "int32", len) == 0
        || strncmp(identifier, "i32", len) == 0
        || strncmp(identifier, "int64", len) == 0
        || strncmp(identifier, "uint8", len) == 0
        || strncmp(identifier, "u8", len) == 0
        || strncmp(identifier, "uint16", len) == 0
        || strncmp(identifier, "u16", len) == 0
        || strncmp(identifier, "uint32", len) == 0
        || strncmp(identifier, "u32", len) == 0
        || strncmp(identifier, "uint64", len) == 0
        || strncmp(identifier, "u64", len) == 0
        || strncmp(identifier, "half", len) == 0
        || strncmp(identifier, "float16", len) == 0
        || strncmp(identifier, "h", len) == 0
        || strncmp(identifier, "f16", len) == 0
        || strncmp(identifier, "float", len) == 0
        || strncmp(identifier, "float32", len) == 0
        || strncmp(identifier, "f", len) == 0
        || strncmp(identifier, "f32", len) == 0
        || strncmp(identifier, "double", len) == 0
        || strncmp(identifier, "float64", len) == 0
        || strncmp(identifier, "d", len) == 0
        || strncmp(identifier, "f64", len) == 0
        || strncmp(identifier, "string", len) == 0
        || strncmp(identifier, "s", len) == 0
        || strncmp(identifier, "ref", len) == 0
        || strncmp(identifier, "r", len) == 0
        || strncmp(identifier, "type", len) == 0
        || strncmp(identifier, "t", len) == 0
        || strncmp(identifier, "base64", len) == 0
        || strncmp(identifier, "z", len) == 0;
}
enum ODDLDataType ODDL_convertIdentifierToDataType(char const* identifier, int len) {
    if(len < 0) {
        len = strlen(identifier);
    }
    if((strncmp(identifier, "bool", len) == 0 && len == 4)
        || (strncmp(identifier, "b", len) == 0 && len == 1)) {
        return ODDLDataTypeBool;
    }
    if((strncmp(identifier, "int8", len) == 0 && len == 4)
        || (strncmp(identifier, "i8", len) == 0 && len == 2)) {
        return ODDLDataTypeInt8;
    }
    if((strncmp(identifier, "int16", len) == 0 && len == 4)
        || (strncmp(identifier, "i16", len) == 0 && len == 3)) {
        return ODDLDataTypeInt16;
    }
    if((strncmp(identifier, "int32", len) == 0 && len == 4)
        || (strncmp(identifier, "i32", len) == 0 && len == 3)) {
        return ODDLDataTypeInt32;
    }
    if((strncmp(identifier, "int64", len) == 0 && len == 4)
        || (strncmp(identifier, "i64", len) == 0 && len == 3)) {
        return ODDLDataTypeInt64;
    }
    if((strncmp(identifier, "uint8", len) == 0 && len == 4)
        || (strncmp(identifier, "u8", len) == 0 && len == 2)) {
        return ODDLDataTypeUInt8;
    }
    if((strncmp(identifier, "uint16", len) == 0 && len == 4)
        || (strncmp(identifier, "u16", len) == 0 && len == 3)) {
        return ODDLDataTypeUInt16;
    }
    if((strncmp(identifier, "uint32", len) == 0 && len == 4)
        || (strncmp(identifier, "u32", len) == 0 && len == 3)) {
        return ODDLDataTypeUInt32;
    }
    if((strncmp(identifier, "uint64", len) == 0 && len == 4)
        || (strncmp(identifier, "u64", len) == 0 && len == 3)) {
        return ODDLDataTypeUInt64;
    }
    if((strncmp(identifier, "half", len) == 0 && len == 4)
        || (strncmp(identifier, "float16", len) == 0 && len == 7)
        || (strncmp(identifier, "h", len) == 0 && len == 1)
        || (strncmp(identifier, "f16", len) == 0 && len == 3)) {
        return ODDLDataTypeHalf;
    }
    if((strncmp(identifier, "float", len) == 0 && len == 5)
        || (strncmp(identifier, "float32", len) == 0 && len == 7)
        || (strncmp(identifier, "f", len) == 0 && len == 1)
        || (strncmp(identifier, "f32", len) == 0 && len == 3)) {
        return ODDLDataTypeFloat;
    }
    if((strncmp(identifier, "double", len) == 0 && len == 6)
        || (strncmp(identifier, "float64", len) == 0 && len == 7)
        || (strncmp(identifier, "d", len) == 0 && len == 1)
        || (strncmp(identifier, "f64", len) == 0 && len == 3)) {
        return ODDLDataTypeDouble;
    }
    if((strncmp(identifier, "string", len) == 0 && len == 6)
        || (strncmp(identifier, "s", len) == 0 && len == 1)) {
        return ODDLDataTypeString;
    }
    if((strncmp(identifier, "ref", len) == 0 && len == 3)
        || (strncmp(identifier, "r", len) == 0 && len == 1)) {
        return ODDLDataTypeRef;
    }
    if((strncmp(identifier, "type", len) == 0 && len == 4)
        || (strncmp(identifier, "t", len) == 0 && len == 1)) {
        return ODDLDataTypeType;
    }
    if((strncmp(identifier, "base64", len) == 0 && len == 6)
        || (strncmp(identifier, "z", len) == 0 && len == 1)) {
        return ODDLDataTypeBase64;
    }
    return ODDLDataTypeInvalid;
}
ODDL_BOOL_T ODDL_isIdentifierReserved(char const* identifier, int len) {
    if(ODDL_isIdentifierDataType(identifier, len)) {
        return ODDL_TRUE;
    }
    if(identifier[0] < 'a'
        || identifier[0] > 'z') {
        return ODDL_FALSE;
    }
    if(len < 0) {
        len = strlen(identifier);
    }
    if(len == 1) {
        return ODDL_FALSE;
    }
    for(int i = 1; i < len; i++) {
        if(identifier[i] < '0'
            || identifier[i] > '9') {
            return ODDL_FALSE;
        }
    }
    return ODDL_TRUE;
}

struct ODDLParserState {
};

#define ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(expr, cleanup) if((expr) < 0) { cleanup; return -1; }
#define ODDL_PARSE_ERROR_CHECK(expr) ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(expr, do{}while(0))

int ODDL_skipWhitespace(char const* ddlMem, int ddlLen, int cursor, struct ODDLParserState* parserState, ODDL_BOOL_T expectingBase64) {
    // Advance cursor to first non-whitespace char
    ODDL_BOOL_T inComment = ODDL_FALSE;
    ODDL_BOOL_T isSLComment = ODDL_FALSE;
    while(1) {
        if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
            if(inComment && !isSLComment) {
                ODDL_reportError(ODDLErrorUnexpectedEndOfFile);
                return -1;
            }
            return cursor;
        }

        char const c = ddlMem[cursor];

        switch(c) {
        case '\n':
        case '\r':
            if(inComment && isSLComment) {
                inComment = ODDL_FALSE;
            }
        case '\t':
        case ' ':
            break;
        case '/':
            if(!expectingBase64) {
                if(!inComment) {
                    if(cursor + 1 < ddlLen) {
                        char const nextC = ddlMem[cursor + 1];
                        if(nextC == '/') {
                            inComment = ODDL_TRUE;
                            isSLComment = ODDL_TRUE;
                        } else if(nextC == '*') {
                            inComment = ODDL_TRUE;
                            isSLComment = ODDL_FALSE;
                        }
                    }
                } else if(!isSLComment) {
                    if(ddlMem[cursor - 1] == '*') {
                        inComment = ODDL_FALSE;
                    }
                }
            }
            break;
        default:
            if(!inComment) {
                return cursor;
            }
            break;
        }

        cursor++;
    }

    ODDL_reportError(ODDLErrorUnknown);
    return -1;
}

int ODDL_parseIdentifier(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    char const** outIdentifier,
    int* outIdentifierLen) {
    int const start = cursor;
    while(1) {
        if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
            if(cursor == start) {
                ODDL_reportError(ODDLErrorUnexpectedEndOfFile);
                return -1;
            }
            return cursor;
        }

        char const c = ddlMem[cursor];

        if((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9' && cursor > start)) {
            cursor++;
            continue;
        }
        break;
    }

    if(outIdentifier != ODDL_NULL) {
        *outIdentifier = &ddlMem[start];
    }
    if(outIdentifierLen != ODDL_NULL) {
        *outIdentifierLen = cursor - start;
    }
    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}


ODDL_BOOL_T ODDL_parseToken(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    char token) {
    if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
        ODDL_reportError(ODDLErrorUnexpectedEndOfFile);
        return -1;
    }

    if(ddlMem[cursor] != token) {
        ODDL_reportError(ODDLErrorUnexpectedToken);
        return -1;
    }
    
    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, ODDL_FALSE);
}

#define ODDL_EOF_CHECK_WITH_CLEANUP(cleanup) if(cursor >= ddlLen || ddlMem[cursor] == '\0') { \
    ODDL_reportError(ODDLErrorUnexpectedEndOfFile); \
    cleanup; \
    return -1; \
}
#define ODDL_EOF_CHECK() ODDL_EOF_CHECK_WITH_CLEANUP(do{}while(0))

int ODDL_parseDecimalLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        ODDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            num *= 10;
            num += c - '0';
            break;
        default:
            if(cursor == start) {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}
static int8_t ODDL_hexLookup[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // 0-9
    -1, -1, -1, -1, -1, -1, -1, // :-@
    10, 11, 12, 13, 14, 15, 16, // A-F
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // G-`
    10, 11, 12, 13, 14, 15, 16 // a-f
};
int ODDL_parseHexLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        ODDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c >= '0' && c <= 'f') {
                int8_t val = ODDL_hexLookup[c - '0'];
                num *= 16;
                num += c - '0';
            } else {
                if(cursor == start) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}
int ODDL_parseOctalLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        ODDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c >= '0' && c <= '7') {
                num *= 8;
                num += c - '0';
            } else {
                if(cursor == start) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}
int ODDL_parseBinaryLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        ODDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c == '0' || c == '1') {
                num <<= 1;
                num += c - '0';
            } else {
                if(cursor == start) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}
int ODDL_parseCharLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '\''));
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        ODDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        if(prevC == '\\') {
            num *= 255;
            switch(c) {
            case '"':
            case '\'':
            case '?':
            case '\\':
                num += c;
                break;
            case 'a':
                num += '\a';
                break;
            case 'b':
                num += '\b';
                break;
            case 'f':
                num += '\f';
                break;
            case 'n':
                num += '\n';
                break;
            case 'r':
                num += '\r';
                break;
            case 't':
                num += '\t';
                break;
            case 'v':
                num += '\v';
                break;
            case 'x':
                // @todo look-ahead
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, 'x'));
                uint64_t spec;
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseHexLiteral(&ddlMem[cursor + 1], 2, 0, ODDL_NULL, &spec))
                num += spec;
                break;
            default:
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
        } else {
            switch(c) {
            case '\\':
                // Escape character, do nothing until resolution next character
                break;
            case '\'':
                // End of character list
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '\''));
                goto ddl_break;
            default:
                num *= 255;
                num += c;
                break;
            }
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}
int ODDL_parseIntegerLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    uint64_t* outVal) {
    ODDL_EOF_CHECK();
    int const start = cursor;
    int sign = ddlMem[cursor] == '-' ? -1 : 1;
    if(ddlMem[cursor] == '-'
        || ddlMem[cursor] == '+') {
        cursor++;
    } 

    uint64_t num;

    ODDL_BOOL_T parsed = ODDL_FALSE;
    if(ddlMem[cursor] == '\'') {
        ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseCharLiteral(ddlMem, ddlLen, cursor, parserState, &num));
        parsed = ODDL_TRUE;
    } else {
        if(cursor + 2 < ddlLen
            && ddlMem[cursor] == '0') {
            switch(ddlMem[cursor + 1]) {
            case 'x':
            case 'X':
                cursor += 2;
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseHexLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = ODDL_TRUE;
                break;
            case 'o':
            case 'O':
                cursor += 2;
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseOctalLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = ODDL_TRUE;
                break;
            case 'b':
            case 'B':
                cursor += 2;
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseBinaryLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = ODDL_TRUE;
                break;
            default:
                break;
            }
        }
    }

    if(!parsed) {
        ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseDecimalLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    }

    num *= sign;

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }    

    return cursor;
}

int ODDL_parseFloatLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    int parsingBytes,
    double* outVal) {
    if(parsingBytes != 2
        && parsingBytes != 4
        && parsingBytes != 8) {
        ODDL_reportError(ODDLErrorUnknown);
        return -1;
    }

    ODDL_EOF_CHECK();
    int const start = cursor;
    int sign = ddlMem[cursor] == '-' ? -1 : 1;
    if(ddlMem[cursor] == '-'
        || ddlMem[cursor] == '+') {
        cursor++;
    } 

    double num = 0;

    ODDL_BOOL_T parsed = ODDL_FALSE;
    if(cursor + 2 < ddlLen
        && ddlMem[cursor] == '0') {
        uint64_t nbits = 0;
        switch(ddlMem[cursor + 1]) {
        case 'x':
        case 'X':
            cursor += 2;
            ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseHexLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            if((nbits >> (parsingBytes * 8)) > 0) {
                ODDL_reportError(ODDLErrorOutOfRange);
                return -1;
            }
            parsed = ODDL_TRUE;
            break;
        case 'o':
        case 'O':
            cursor += 2;
            ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseOctalLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            num = *(double*)&nbits;
            parsed = ODDL_TRUE;
            break;
        case 'b':
        case 'B':
            cursor += 2;
            ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseBinaryLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            num = *(double*)&nbits;
            parsed = ODDL_TRUE;
            break;
        default:
            break;
        }
        if(parsed) {
            switch(parsingBytes) {
            case 2:
                {
                    uint32_t fbits = ODDL_convertHalfBitsToFloatBits((uint16_t)nbits);
                    num = (double)*(float*)&fbits;
                }
                break;
            case 4:
                num = (double)*(float*)&nbits;
                break;
            case 8:
                num = *(double*)&nbits;
                break;
            default:
                break;
            }
        }
    }

    if(!parsed) {
        double mul = 1;
        double expSign = 1;
        double exp = 0;
        ODDL_BOOL_T seenDecimal = ODDL_FALSE;
        ODDL_BOOL_T seenExponent = ODDL_FALSE;
        ODDL_BOOL_T expSpecified = ODDL_FALSE;

        char prevC = '\0';
        while(1) {
            ODDL_EOF_CHECK();

            char const c = ddlMem[cursor];
            switch(c) {
            case '_':
                if(cursor == start
                    || prevC == '_'
                    || prevC == '.'
                    || prevC == 'e'
                    || prevC == 'E') {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
                break;
            case '.':
                if(seenDecimal
                    || seenExponent) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
                seenDecimal = ODDL_TRUE;
                break;
            case 'e':
            case 'E':
                if(seenExponent
                    || cursor == start) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
                seenExponent = ODDL_TRUE;
                break;
            case '-':
            case '+':
                if(!seenExponent
                    || (prevC != 'e' && prevC != 'E')) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
                expSign = c == '-' ? -1 : 1;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(seenExponent) {
                    expSpecified = ODDL_TRUE;
                    exp *= 10;
                    exp += c - '0';
                } else {
                    if(seenDecimal) {
                        mul /= 10;
                    }
                    num *= 10;
                    num += c - '0';
                }
                break;    
            default:
                if(seenExponent && !expSpecified) {
                    ODDL_reportError(ODDLErrorUnexpectedToken);
                    return -1;
                }
                ODDL_PARSE_ERROR_CHECK(cursor = ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE));
                goto ddl_break;
            }

            prevC = c;
            cursor++;
        
        ddl_continue:
            continue;
        ddl_break:
            break;
        }

        num *= mul;
        exp *= expSign;
        num *= ODDL_DPOW(10, exp);
    }

    num *= sign;

    if(outVal != ODDL_NULL) {
        *outVal = num;
    }    

    return cursor;
}

int ODDL_parseHalf(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    ODDL_EOF_CHECK();
    double dnum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(ODDL_HALF_T), &dnum));

    float fnum = (float)dnum;
    if(sizeof(ODDL_HALF_T) == sizeof(float)) {
        if(outVal != ODDL_NULL) {
            *(float*)outVal = fnum;
        }
    } else {
        if(outVal != ODDL_NULL) {
            uint32_t fbits = *(uint32_t*)&fnum;
            uint16_t hbits = ODDL_convertFloatBitsToHalfBits(fbits);
            *(ODDL_HALF_T*)outVal = *(ODDL_HALF_T*)&hbits;
        }
    }

    return cursor;
}
int ODDL_parseFloat(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    ODDL_EOF_CHECK();
    double dnum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(float), &dnum));

    // @todo Check if double can be converted into float?
    float num = dnum;
    
    if(outVal != ODDL_NULL) {
        *(float*)outVal = num;
    }

    return cursor;
}
int ODDL_parseDouble(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    ODDL_EOF_CHECK();
    double dnum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(double), &dnum));
    
    if(outVal != ODDL_NULL) {
        *(double*)outVal = dnum;
    }

    return cursor;
}

int ODDL_parseBool(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    ODDL_EOF_CHECK();
    ODDL_BOOL_T b;
    if(ddlMem[cursor] == '0'
        || ddlMem[cursor] == '1') {
        b = ddlMem[cursor] == '1' ? ODDL_TRUE : ODDL_FALSE;
        cursor++;
    } else {
        if((cursor + 4) >= ddlLen) {
            ODDL_reportError(ODDLErrorUnexpectedEndOfFile);
            return -1;
        } else {
            if(cursor + 5 < ddlLen
                && strcmp(&ddlMem[cursor], "false") == 0) {
                b = ODDL_FALSE;
                cursor += 5;
            } else if(strcmp(&ddlMem[cursor], "true") == 0) {
                b = ODDL_TRUE;
                cursor += 4;
            } else {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                return -1;
            }
        }
    }

    if(outVal != ODDL_NULL) {
        *(ODDL_BOOL_T*)outVal = b;
    }

    return ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE);
}

int ODDL_parseInt8(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -128 || num > 127) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(int8_t*)outVal = (int8_t)num;
    }

    return cursor;
}
int ODDL_parseInt16(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -32768 || num > 32767) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(int16_t*)outVal = (int16_t)num;
    }

    return cursor;
}
int ODDL_parseInt32(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -2147483648 || num > 2147483647) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(int32_t*)outVal = (int32_t)num;
    }

    return cursor;
}
int ODDL_parseInt64(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;

    if(outVal != ODDL_NULL) {
        *(int64_t*)outVal = num;
    }

    return cursor;
}
int ODDL_parseUInt8(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 8) > 0) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(uint8_t*)outVal = (uint8_t)num;
    }

    return cursor;
}
int ODDL_parseUInt16(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 16) > 0) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(uint16_t*)outVal = (uint16_t)num;
    }

    return cursor;
}
int ODDL_parseUInt32(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 32) > 0) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != ODDL_NULL) {
        *(uint32_t*)outVal = (uint32_t)num;
    }

    return cursor;
}
int ODDL_parseUInt64(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    return ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, (uint64_t*)outVal);
}

int ODDL_parseType(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    void* outVal) {
    char const* identifier;
    int identifierLen;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen));

    enum ODDLDataType dtype = ODDL_convertIdentifierToDataType(identifier, identifierLen);
    if(dtype == ODDLDataTypeInvalid) {
        ODDL_reportError(ODDLErrorUnexpectedToken);
        return -1;
    } 

    if(outVal != ODDL_NULL) {
        *(enum ODDLDataType*)outVal = dtype;
    }

    return cursor;
}

static int (*ODDL_dataTypeParsers[])(char const*, int, int, struct ODDLParserState*, void*) = {
    ODDL_NULL, // Invalid
    &ODDL_parseBool,
    &ODDL_parseInt8,
    &ODDL_parseInt16,
    &ODDL_parseInt32,
    &ODDL_parseInt64,
    &ODDL_parseUInt8,
    &ODDL_parseUInt16,
    &ODDL_parseUInt32,
    &ODDL_parseUInt64,
    &ODDL_parseHalf,
    &ODDL_parseFloat,
    &ODDL_parseDouble,
    ODDL_NULL, // String
    ODDL_NULL, // Ref
    &ODDL_parseType, // Type
    ODDL_NULL // Base64
};
static int ODDL_dataTypeSizes[] = {
    -1, // Invalid
    sizeof(ODDL_BOOL_T),
    sizeof(int8_t),
    sizeof(int16_t),
    sizeof(int32_t),
    sizeof(int64_t),
    sizeof(uint8_t),
    sizeof(uint16_t),
    sizeof(uint32_t),
    sizeof(uint64_t),
    sizeof(ODDL_HALF_T),
    sizeof(float),
    sizeof(double),
    -1, // String
    -1, // Ref
    sizeof(enum ODDLDataType),
    -1 // Base64
};

int ODDL_parseInnerProps(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    struct ODDLProp** outPropStart,
    int* outPropCount) {
    struct ODDLProp* propStart = ODDL_NULL;
    struct ODDLProp** propNext = ODDL_NULL;
    int propCount = 0;

    int const start = cursor;
    while(1) {
        ODDL_EOF_CHECK();

        if(ddlMem[cursor] == ')') {
            break;
        }

        // If we are on a ',', we need to skip to the identifier
        if(ddlMem[cursor] == ',') {
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), ODDL_freeProp(propStart));
        }

        // Identifier
        char const* identifier;
        int identifierLen;
        ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen), ODDL_freeProp(propStart));

        struct ODDLProp* prop = (struct ODDLProp*)malloc(sizeof(struct ODDLProp));
        if(prop == ODDL_NULL) {
            ODDL_reportError(ODDLErrorOutOfMemory);
            ODDL_freeProp(propStart);
            return -1;
        }
        *prop = ODDL_createProp();
        if(propStart == ODDL_NULL) {
            propStart = prop;
        } else {
            *propNext = prop;
        }
        propNext = &prop->next;
        propCount++;
        prop->identifier = (char*)malloc((identifierLen + 1) * sizeof(char));
        if(prop->identifier == ODDL_NULL) {
            ODDL_reportError(ODDLErrorOutOfMemory);
            ODDL_freeProp(propStart);
            return -1;
        }
        strncpy(prop->identifier, identifier, identifierLen);
        prop->identifier[identifierLen] = '\0';

        // Value
        ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE), ODDL_freeProp(propStart));
        ODDL_EOF_CHECK_WITH_CLEANUP(ODDL_freeProp(propStart));
        if(ddlMem[cursor] == ',' || ddlMem[cursor] == ')') {
            // Boolean true
            prop->value = strdup("1");
            prop->size = 1;
            prop->storageType = ODDLPropStorageTypeRawString;
            if(prop->value == ODDL_NULL) {
                ODDL_reportError(ODDLErrorOutOfMemory);
                ODDL_freeProp(propStart);
                return -1;
            }
            continue;
        }

        // Expecting a '='
        ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '='), ODDL_freeProp(propStart));

        // Grab raw string value
        ODDL_BOOL_T inString = ODDL_FALSE;
        ODDL_BOOL_T escaping = ODDL_FALSE;
        int const rawStrStart = cursor;
        while(1) {
            if(cursor < ddlLen && ddlMem[cursor] == '\0') {
                ODDL_reportError(ODDLErrorUnexpectedEndOfFile);
                ODDL_freeProp(propStart);
                return -1;
            }
            char const c = ddlMem[cursor];

            if(c == ',' || c == ')') {
                break;
            }

            if(c == '"') {
                if(!escaping) {
                    inString = !inString;
                }
            }
            if(escaping) {
                escaping = ODDL_FALSE;
            }
            if(inString) {
                if(!escaping && c == '\\') {
                    escaping = ODDL_TRUE;
                }
            }

            cursor++;
        }
        int const rawStrLen = cursor - rawStrStart;
        prop->size = rawStrLen;
        prop->value = (char*)malloc((rawStrLen + 1) * sizeof(char));
        if(prop->value == ODDL_NULL) {
            ODDL_reportError(ODDLErrorOutOfMemory);
            ODDL_freeProp(propStart);
            return -1;
        }
        strncpy(prop->value, &ddlMem[rawStrStart], rawStrLen);
        ((char*)(prop->value))[rawStrLen] = '\0';
    }

    if(outPropStart != ODDL_NULL) {
        *outPropStart = propStart;
    }
    if(outPropCount != ODDL_NULL) {
        *outPropCount = propCount;
    }

    return cursor;
}
int ODDL_parseInnerDataWithParser(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    struct ODDL* struc) {
    if(struc == ODDL_NULL) {
        ODDL_reportError(ODDLErrorUnknown);
        return -1;
    }

    struct ODDLData* dataStart = ODDL_NULL;
    struct ODDLData** dataNext = ODDL_NULL;
    int dataCount = 0;

    while(1) {
        ODDL_EOF_CHECK();

        if(ddlMem[cursor] == '}') {
            break;
        }

        struct ODDLData* data = (struct ODDLData*)malloc(sizeof(struct ODDLData));
        if(data == ODDL_NULL) {
            ODDL_reportError(ODDLErrorOutOfMemory);
            ODDL_freeData(dataStart);
            return -1;
        }
        *data = ODDL_createData(struc->dataType);
        if(dataStart == ODDL_NULL) {
            dataStart = data;
        } else {
            *dataNext = data;
        }
        dataNext = &data->next;
        dataCount++;
        int dataLen = 1;
        if(struc->dataArrayCount > 0) {
            dataLen = struc->dataArrayCount;
        }
        data->size = sizeof(ODDL_dataTypeSizes[(int)data->type]) * dataLen;

        data->data = malloc(data->size);
        if(data == ODDL_NULL) {
            ODDL_reportError(ODDLErrorOutOfMemory);
            ODDL_freeData(dataStart);
            return -1;
        }
        if(struc->dataArrayCount > 0) {
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '{'), ODDL_freeData(dataStart));
            for(int i = 0; i < struc->dataArrayCount; i++) {
                intptr_t ptr = (intptr_t)data->data;
                ptr += i * sizeof(ODDL_dataTypeSizes[(int)data->type]);
                ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_dataTypeParsers[(int)data->type](ddlMem, ddlLen, cursor, parserState, (void*)ptr), ODDL_freeData(dataStart));
                if(i < struc->dataArrayCount - 1) {
                    ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), ODDL_freeData(dataStart));
                } else {
                    ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '}'), ODDL_freeData(dataStart));
                }
            }
        } else {
            // No outer braces
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_dataTypeParsers[(int)data->type](ddlMem, ddlLen, cursor, parserState, data->data), ODDL_freeData(dataStart));
        }

        // Either a `,` or a `}`
        ODDL_EOF_CHECK();
        if(ddlMem[cursor] == ',') {
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), ODDL_freeData(dataStart))
        }
    }

    struc->dataStart = dataStart;
    struc->dataCount = dataCount;

    return cursor;
}
int ODDL_parseStructure(char const* ddlMem, int ddlLen,
    int cursor,
    struct ODDLParserState* parserState,
    struct ODDL** outStruc) {
    char const* identifier;
    int identifierLen;
    ODDL_PARSE_ERROR_CHECK(cursor = ODDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen));

    ODDL_BOOL_T isStrucPrimitive = ODDL_FALSE;
    enum ODDLDataType strucDataType = ODDL_convertIdentifierToDataType(identifier, identifierLen);

    if(strucDataType != ODDLDataTypeInvalid) {
        isStrucPrimitive = ODDL_TRUE;
    } else {
        if(ODDL_isIdentifierReserved(identifier, identifierLen)) {
            ODDL_reportError(ODDLErrorInvalidIdentifier);
            return -1;
        } else {
            isStrucPrimitive = ODDL_FALSE;
        }
    }

    ODDL_EOF_CHECK();

    struct ODDL* struc = (struct ODDL*)malloc(sizeof(struct ODDL));
    if(struc == ODDL_NULL) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return -1;
    }
    *struc = ODDL_createStruct(isStrucPrimitive ? ODDLStructTypePrimitive : ODDLStructTypeDerived);
    if(isStrucPrimitive) {
        struc->dataType = strucDataType;
    }
    struc->identifier = (char*)malloc((identifierLen + 1) * sizeof(char));
    if(struc->identifier == ODDL_NULL) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        ODDL_free(struc);
        return -1;
    }
    strncpy(struc->identifier, identifier, identifierLen);
    struc->identifier[identifierLen] = '\0';

    ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, ODDL_FALSE), ODDL_free(struc));
    ODDL_BOOL_T expectingName = ODDL_TRUE;
    ODDL_BOOL_T expectingProperties = struc->type == ODDLStructTypeDerived;
    ODDL_BOOL_T expectingSubarrayN = struc->type == ODDLStructTypePrimitive;
    ODDL_BOOL_T expectingDataStates = ODDL_FALSE;
    while(1) {
        switch(ddlMem[cursor]) {
        case '$':
        case '%':
            if(!expectingName) {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                ODDL_free(struc);
                return -1;
            }
            struc->isNameGlobal = ddlMem[cursor] == '$';
            cursor++;
            char const* name;
            int nameLen;
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &name, &nameLen), ODDL_free(struc));
            struc->name = (char*)malloc((nameLen + 1) * sizeof(char));
            if(struc->name == ODDL_NULL) {
                ODDL_reportError(ODDLErrorOutOfMemory);
                ODDL_free(struc);
                return -1;
            }
            strncpy(struc->name, name, nameLen);
            struc->name[nameLen] = '\0';

            expectingSubarrayN = expectingDataStates = expectingName = ODDL_FALSE;
            break;
        case '{':
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '{'), ODDL_free(struc));

            if(struc->type == ODDLStructTypeDerived) {
                struct ODDL** subNext = &struc->subStart;
                while(cursor < ddlLen
                    && ddlMem[cursor] != '\0'
                    && ddlMem[cursor] != '}') {
                    struct ODDL* subStruc = ODDL_NULL;
                    ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseStructure(ddlMem, ddlLen, cursor, parserState, &subStruc), ODDL_free(struc));
                    *subNext = subStruc;
                    subNext = &subStruc->next;
                    struc->subCount++;
                }
            } else {
                ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseInnerDataWithParser(ddlMem, ddlLen, cursor, parserState, struc), ODDL_free(struc));
            }

            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '}'), ODDL_free(struc));
            goto ddl_break;
        case '[':
            if(!expectingSubarrayN) {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                ODDL_free(struc);
                return -1;
            }

            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, ODDL_FALSE), ODDL_free(struc));
            uint64_t subarrayN;
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &subarrayN), ODDL_free(struc));
            if(subarrayN <= 0) {
                ODDL_reportError(ODDLErrorOutOfRange);
                ODDL_free(struc);
                return -1;
            }
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, ']'), ODDL_free(struc));
            struc->dataArrayCount = subarrayN;

            expectingSubarrayN = ODDL_FALSE;
            expectingDataStates = ODDL_TRUE;
            break;
        case '*':
            if(!expectingDataStates) {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                ODDL_free(struc);
                return -1;
            }

            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, ODDL_FALSE), ODDL_free(struc));
            struc->isDataStates = ODDL_TRUE;

            expectingDataStates = ODDL_FALSE;
            break;
        case '(':
            if(!expectingProperties) {
                ODDL_reportError(ODDLErrorUnexpectedToken);
                ODDL_free(struc);
                return -1;
            }

            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, '('), ODDL_free(struc));
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseInnerProps(ddlMem, ddlLen, cursor, parserState, &struc->propStart, &struc->propCount), ODDL_free(struc));
            ODDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = ODDL_parseToken(ddlMem, ddlLen, cursor, parserState, ')'), ODDL_free(struc));

            expectingProperties = ODDL_FALSE;
            break;

        default:
            ODDL_reportError(ODDLErrorUnexpectedToken);
            return -1;
        }

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outStruc != ODDL_NULL) {
        *outStruc = struc;
    }

    return cursor;
}

struct ODDL* ODDL_parseFromString(char const* ddlStr) {
    struct ODDL* root = ODDL_create();
    if(root == ODDL_NULL) {
        ODDL_reportError(ODDLErrorOutOfMemory);
        return ODDL_NULL;
    }

    int const ddlLen = strlen(ddlStr);
    struct ODDLParserState parserState;
    int cursor = ODDL_skipWhitespace(ddlStr, ddlLen, 0, &parserState, ODDL_FALSE);

    struct ODDL** subNext = &root->subStart;
    while(cursor < ddlLen && ddlStr[cursor] != '\0') {
        struct ODDL* subStruc = ODDL_NULL;
        cursor = ODDL_parseStructure(ddlStr, ddlLen, cursor, &parserState, &subStruc);
        if(cursor < 0) {
            ODDL_free(root);
            return ODDL_NULL;
        }
        *subNext = subStruc;
        subNext = &subStruc->next;
        root->subCount++;
    }

    return root;
}

char const* ODDL_getPropIdentifier(struct ODDLProp* prop) {
    return prop->identifier;
}
struct ODDLProp* ODDL_getPropNext(struct ODDLProp* prop) {
    return prop->next;
}

ODDL_BOOL_T ODDL_getPropBoolValue(struct ODDLProp* prop, ODDL_BOOL_T* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseBool((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropInt8Value(struct ODDLProp* prop, int8_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseInt8((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropInt16Value(struct ODDLProp* prop, int16_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseInt16((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropInt32Value(struct ODDLProp* prop, int32_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseInt32((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropInt64Value(struct ODDLProp* prop, int64_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseInt64((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropUInt8Value(struct ODDLProp* prop, uint8_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseUInt8((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropUInt16Value(struct ODDLProp* prop, uint16_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseUInt16((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropUInt32Value(struct ODDLProp* prop, uint32_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseUInt32((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropUInt64Value(struct ODDLProp* prop, uint64_t* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    return ODDL_parseUInt64((char const*)prop->value, prop->size, 0, ODDL_NULL, outVal);
}
ODDL_BOOL_T ODDL_getPropHalfValue(struct ODDLProp* prop, ODDL_HALF_T* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    // return ODDL_parseStringAsHalf((char*)prop->value, prop->size, outVal);
}
ODDL_BOOL_T ODDL_getPropFloatValue(struct ODDLProp* prop, float* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    // return ODDL_parseStringAsFloat((char*)prop->value, prop->size, outVal);
}
ODDL_BOOL_T ODDL_getPropDoubleValue(struct ODDLProp* prop, double* outVal) {
    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    // return ODDL_parseStringAsDouble((char*)prop->value, prop->size, outVal);
}
ODDL_BOOL_T ODDL_getPropStringValue(struct ODDLProp* prop, char const** outVal) {
    if(prop->storageType == ODDLPropStorageTypeString) {
        if(outVal != ODDL_NULL) {
            *outVal = (char const*)prop->value;
        }
        return ODDL_TRUE;
    }

    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    void* valuePtr = prop->value;
    // if(!ODDL_parseStringAsString((char*)prop->value, prop->size, (char**)&prop->value)) {
    //     return ODDL_FALSE;
    // }
    free(valuePtr);
    prop->storageType = ODDLPropStorageTypeString;
    return ODDL_getPropStringValue(prop, outVal);
}
ODDL_BOOL_T ODDL_getPropRefValue(struct ODDLProp* prop, struct ODDL** outVal) {
    ODDL_reportError(ODDLErrorUnknown);
    return ODDL_FALSE;
}
ODDL_BOOL_T ODDL_getPropTypeValue(struct ODDLProp* prop, enum ODDLDataType* outVal) {
    if(prop->storageType == ODDLPropStorageTypeType) {
        if(outVal != ODDL_NULL) {
            *outVal = *(enum ODDLDataType*)prop->value;
        }
        return ODDL_TRUE;
    }

    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    void* valuePtr = prop->value;
    // enum ODDLDataType* dataType = malloc(sizeof(enum ODDLDataType)); 
    // if(!ODDL_parseStringAsType((char*)prop->value, prop->size, dataType)) {
    //     return ODDL_FALSE;
    // }
    // free(valuePtr);
    // prop->value = valuePtr;
    // prop->storageType = ODDLPropStorageTypeType;
    // return ODDL_getPropTypeValue(prop, outVal);
}
ODDL_BOOL_T ODDL_getPropBase64Value(struct ODDLProp* prop, void const** outVal, int* outSize) {
    if(prop->storageType == ODDLPropStorageTypeType) {
        if(outVal != ODDL_NULL) {
            *outVal = (enum ODDLDataType*)prop->value;
        }
        return ODDL_TRUE;
    }

    if(prop->storageType != ODDLPropStorageTypeRawString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }

    void* valuePtr = prop->value;
    size_t dataSize;
    // if(!ODDL_parseStringAsBase64((char*)prop->value, prop->size, (uint8_t**)&prop->value, &dataSize)) {
    //     return ODDL_FALSE;
    // }
    free(valuePtr);
    prop->storageType = ODDLPropStorageTypeBase64;
    prop->size = dataSize;
    return ODDL_getPropBase64Value(prop, outVal, outSize);
}

enum ODDLStructType ODDL_getStructType(struct ODDL* struc) {
    return struc->type;
}
ODDL_BOOL_T ODDL_isStructRoot(struct ODDL* struc) {
    return struc->type == ODDLStructTypeRoot;
}
ODDL_BOOL_T ODDL_isStructDerived(struct ODDL* struc) {
    return struc->type == ODDLStructTypeDerived;
}
ODDL_BOOL_T ODDL_isStructPrimitive(struct ODDL* struc) {
    return struc->type == ODDLStructTypePrimitive;
}

char const* ODDL_getStructIdentifier(struct ODDL* struc) {
    if(struc->identifier == ODDL_NULL) {
        return "";
    }
    return struc->identifier;
}
ODDL_BOOL_T ODDL_hasStructName(struct ODDL* struc) {
    return struc->name != ODDL_NULL;
}
char const* ODDL_getStructName(struct ODDL* struc) {
    if(struc->name == ODDL_NULL) {
        return "";
    }
    return struc->name;
}
ODDL_BOOL_T ODDL_isStructNameGlobal(struct ODDL* struc) {
    return struc->isNameGlobal;
}
ODDL_BOOL_T ODDL_isStructNameLocal(struct ODDL* struc) {
    return !struc->isNameGlobal;
}

int ODDL_getStructPropCount(struct ODDL* struc) {
    return struc->propCount;
}
struct ODDLProp* ODDL_getStructPropStart(struct ODDL* struc) {
    return struc->propStart;
}
struct ODDLProp* ODDL_getStructPropByIndex(struct ODDL* struc, int index) {
    int i = 0;
    struct ODDLProp* prop = struc->propStart;
    do {
        if(prop == ODDL_NULL) {
            return ODDL_NULL;
        }
        prop = prop->next;
    }while(++i < index);
    return prop;
}
struct ODDLProp* ODDL_findStructProp(struct ODDL* struc, char const* propIdentifier) {
    struct ODDLProp* prop = struc->propStart;
    while(prop != ODDL_NULL) {
        if(strcmp(prop->identifier, propIdentifier) == 0) {
            return prop;
        }
        prop = prop->next;
    }
    return ODDL_NULL;
}

struct ODDL* ODDL_getStructSiblingNext(struct ODDL* struc) {
    return struc->next;
}
struct ODDL* ODDL_getStructSiblingNextByIdentifier(struct ODDL* struc, char const* id) {
    while(struc != ODDL_NULL) {
        if(strcmp(struc->identifier, id) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    return ODDL_NULL;
}

int ODDL_getStructSubCount(struct ODDL* struc) {
    return struc->subCount;
}
struct ODDL* ODDL_getStructSubStart(struct ODDL* struc) {
    return struc->subStart;
}
struct ODDL* ODDL_getStructSubByIndex(struct ODDL* struc, int index) {
    struct ODDL* sub = struc->subStart;
    int i = 0;
    do {
        if(sub == ODDL_NULL) {
            return ODDL_NULL;
        }
        sub = sub->next;
    } while(++i < index);
    return sub;
}
struct ODDL* ODDL_findStructSubByName(struct ODDL* struc, char const* name) {
    struct ODDL* sub = struc->subStart;
    while(sub != ODDL_NULL) {
        if(strcmp(sub->name, name) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return ODDL_NULL;
}
struct ODDL* ODDL_findStructSubByIdentifier(struct ODDL* struc, char const* id) {
    struct ODDL* sub = struc->subStart;
    while(sub != ODDL_NULL) {
        if(strcmp(sub->identifier, id) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return ODDL_NULL;
}

ODDL_BOOL_T ODDL_isStructDataFlat(struct ODDL* struc) {
    return struc->dataArrayCount == 0;
}
ODDL_BOOL_T ODDL_isStructDataArray(struct ODDL* struc) {
    return struc->dataArrayCount > 0;
}
int ODDL_getStructDataArraySize(struct ODDL* struc) {
    return struc->dataArrayCount;
}
ODDL_BOOL_T ODDL_hasStructDataStates(struct ODDL* struc) {
    return struc->isDataStates;
}
int ODDL_getStructDataCount(struct ODDL* struc) {
    return struc->dataCount;
}
struct ODDLData* ODDL_getStructDataStart(struct ODDL* struc) {
    return struc->dataStart;
}
struct ODDLData* ODDL_getStructDataByIndex(struct ODDL* struc, int index) {
    struct ODDLData* data = struc->dataStart;
    int i = 0;
    do {
        if(data == ODDL_NULL) {
            return ODDL_NULL;
        }
        data = data->next;
    } while(++i < index);
    return data;
}

enum ODDLDataType ODDL_getStructDataType(struct ODDL* struc) {
    return struc->dataType;
}
ODDL_BOOL_T ODDL_isStructDataBool(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeBool;
}
ODDL_BOOL_T ODDL_isStructDataInt8(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeInt8;
}
ODDL_BOOL_T ODDL_isStructDataInt16(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeInt16;
}
ODDL_BOOL_T ODDL_isStructDataInt32(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeInt32;
}
ODDL_BOOL_T ODDL_isStructDataInt64(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeInt64;
}
ODDL_BOOL_T ODDL_isStructDataUInt8(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeUInt8;
}
ODDL_BOOL_T ODDL_isStructDataUInt16(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeUInt16;
}
ODDL_BOOL_T ODDL_isStructDataUInt32(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeUInt32;
}
ODDL_BOOL_T ODDL_isStructDataUInt64(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeUInt64;
}
ODDL_BOOL_T ODDL_isStructDataHalf(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeHalf;
}
ODDL_BOOL_T ODDL_isStructDataFloat(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeFloat;
}
ODDL_BOOL_T ODDL_isStructDataDouble(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeDouble;
}
ODDL_BOOL_T ODDL_isStructDataString(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeString;
}
ODDL_BOOL_T ODDL_isStructDataRef(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeRef;
}
ODDL_BOOL_T ODDL_isStructDataType(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeType;
}
ODDL_BOOL_T ODDL_isStructDataBase64(struct ODDL* struc) {
    return struc->dataType == ODDLDataTypeBase64;
}

ODDL_BOOL_T ODDL_getDataBoolValue(struct ODDLData* data, ODDL_BOOL_T* outVal) {
    if(data->type != ODDLDataTypeBool) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(ODDL_BOOL_T*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataBoolArrayValue(struct ODDLData* data, ODDL_BOOL_T* outVal, int count) {
    if(data->type != ODDLDataTypeBool) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(ODDL_BOOL_T);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((ODDL_BOOL_T*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt8Value(struct ODDLData* data, int8_t* outVal) {
    if(data->type != ODDLDataTypeInt8) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt8ArrayValue(struct ODDLData* data, int8_t* outVal, int count) {
    if(data->type != ODDLDataTypeInt8) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(int8_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt16Value(struct ODDLData* data, int16_t* outVal) {
    if(data->type != ODDLDataTypeInt16) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(int16_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt16ArrayValue(struct ODDLData* data, int16_t* outVal, int count) {
    if(data->type != ODDLDataTypeInt16) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int16_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt32Value(struct ODDLData* data, int32_t* outVal) {
    if(data->type != ODDLDataTypeInt32) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(int32_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt32ArrayValue(struct ODDLData* data, int32_t* outVal, int count) {
    if(data->type != ODDLDataTypeInt32) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(int32_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int32_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt64Value(struct ODDLData* data, int64_t* outVal) {
    if(data->type != ODDLDataTypeInt64) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(int64_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataInt64ArrayValue(struct ODDLData* data, int64_t* outVal, int count) {
    if(data->type != ODDLDataTypeInt16) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt8Value(struct ODDLData* data, uint8_t* outVal) {
    if(data->type != ODDLDataTypeUInt8) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt8ArrayValue(struct ODDLData* data, uint8_t* outVal, int count) {
    if(data->type != ODDLDataTypeUInt8) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint8_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint8_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt16Value(struct ODDLData* data, uint16_t* outVal) {
    if(data->type != ODDLDataTypeUInt16) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(uint16_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt16ArrayValue(struct ODDLData* data, uint16_t* outVal, int count) {
    if(data->type != ODDLDataTypeUInt16) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint16_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint16_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt32Value(struct ODDLData* data, uint32_t* outVal) {
    if(data->type != ODDLDataTypeUInt32) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(uint32_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt32ArrayValue(struct ODDLData* data, uint32_t* outVal, int count) {
    if(data->type != ODDLDataTypeUInt32) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint32_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint32_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt64Value(struct ODDLData* data, uint64_t* outVal) {
    if(data->type != ODDLDataTypeUInt64) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(uint64_t*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataUInt64ArrayValue(struct ODDLData* data, uint64_t* outVal, int count) {
    if(data->type != ODDLDataTypeUInt64) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint64_t);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint64_t*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataHalfValue(struct ODDLData* data, ODDL_HALF_T* outVal) {
    if(data->type != ODDLDataTypeHalf) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(ODDL_HALF_T*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataHalfArrayValue(struct ODDLData* data, ODDL_HALF_T* outVal, int count) {
    if(data->type != ODDLDataTypeHalf) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(ODDL_HALF_T);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((ODDL_HALF_T*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataFloatValue(struct ODDLData* data, float* outVal) {
    if(data->type != ODDLDataTypeFloat) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(float*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataFloatArrayValue(struct ODDLData* data, float* outVal, int count) {
    if(data->type != ODDLDataTypeFloat) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(float);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((float*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataDoubleValue(struct ODDLData* data, double* outVal) {
    if(data->type != ODDLDataTypeDouble) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(double*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataDoubleArrayValue(struct ODDLData* data, double* outVal, int count) {
    if(data->type != ODDLDataTypeDouble) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(double);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((double*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataStringValue(struct ODDLData* data, char const** outVal) {
    if(data->type != ODDLDataTypeString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    if(outVal != ODDL_NULL) {
        *outVal = (char*)data->data;
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataStringArrayValue(struct ODDLData* data, char const** outVal, int count) {
    if(data->type != ODDLDataTypeString) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores string count instead of total data size
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }

    char const* strStart = (char*)data->data;

    if(outVal != ODDL_NULL) {
        outVal[0] = strStart;
        for(int i = 1; i < count; i++) {
            strStart = strStart + strlen(strStart) + 2;
            outVal[i] = strStart;
        }
    }

    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataRefValue(struct ODDLData* data, struct ODDL** outVal) {
    ODDL_reportError(ODDLErrorUnknown);
    return ODDL_FALSE;
}
ODDL_BOOL_T ODDL_getDataRefArrayValue(struct ODDLData* data, struct ODDL** outVal, int count) {
    ODDL_reportError(ODDLErrorUnknown);
    return ODDL_FALSE;
}
ODDL_BOOL_T ODDL_getDataTypeValue(struct ODDLData* data, enum ODDLDataType* outVal) {
    if(data->type != ODDLDataTypeType) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    *outVal = *(enum ODDLDataType*)data->data;
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataTypeArrayValue(struct ODDLData* data, enum ODDLDataType* outVal, int count) {
    if(data->type != ODDLDataTypeType) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size / sizeof(enum ODDLDataType);
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((enum ODDLDataType*)data->data)[i];
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataBase64Value(struct ODDLData* data, void const** outVal, int* outSize) {
    if(data->type != ODDLDataTypeBase64) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    struct ODDLBase64Data* base64Data = (struct ODDLBase64Data*)data->data;

    if(outVal != ODDL_NULL) {
        if(outSize == ODDL_NULL) {
            ODDL_reportError(ODDLErrorUnknown);
            return ODDL_FALSE;
        }
        *outVal = base64Data->data;
        *outSize = base64Data->size;
    }
    return ODDL_TRUE;
}
ODDL_BOOL_T ODDL_getDataBase64ArrayValue(struct ODDLData* data, void const** outVal, int* outSizes, int count) {
    if(data->type != ODDLDataTypeBase64) {
        ODDL_reportError(ODDLErrorInvalidType);
        return ODDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores blob count instead of total data size
    if(dataCount < count) {
        ODDL_reportError(ODDLErrorOutOfRange);
        return ODDL_FALSE;
    }

    if(outVal != ODDL_NULL) {
        if(outSizes == ODDL_NULL) {
            ODDL_reportError(ODDLErrorUnknown);
            return ODDL_FALSE;
        }

        uint8_t* dataStart = (uint8_t*)data->data;
        for(int i = 0; i < count; i++) {
            // First sizeof(uint64_t) bytes store size of blob after it, in bytes 
            uint64_t blobSize = ((uint64_t*)dataStart)[0];

            outVal[i] = dataStart;    
            outSizes[i] = blobSize;
            dataStart += sizeof(uint64_t) + blobSize;
        }
    }
    return ODDL_TRUE;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* ODDL_H */
