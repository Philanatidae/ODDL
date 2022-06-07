#ifndef DDL_H
#define DDL_H

#ifdef __cplusplus
extern "C" {
#endif

#define DDL_VERSION_MAJOR 0
#define DDL_VERSION_MINOR 1
#define DDL_VERSION_PATCH 0

#include <stddef.h>
#include <stdint.h>

#ifndef DDL_TRUE
#define DDL_TRUE 1
#endif
#ifndef DDL_FALSE
#define DDL_FALSE 0
#endif

#ifndef DDL_BOOL_T
#define DDL_BOOL_T int
#endif

#ifndef DDL_NULL
#define DDL_NULL 0
#endif

#ifndef DDL_HALF_T
#define DDL_HALF_T float
#endif

enum DDLStructType {
    DDLStructTypeRoot,
    DDLStructTypeDerived,
    DDLStructTypePrimitive
};
enum DDLDataType {
    DDLDataTypeInvalid = 0,
    DDLDataTypeBool,
    DDLDataTypeInt8,
    DDLDataTypeInt16,
    DDLDataTypeInt32,
    DDLDataTypeInt64,
    DDLDataTypeUInt8,
    DDLDataTypeUInt16,
    DDLDataTypeUInt32,
    DDLDataTypeUInt64,
    DDLDataTypeHalf,
    DDLDataTypeFloat,
    DDLDataTypeDouble,
    DDLDataTypeString,
    DDLDataTypeRef,
    DDLDataTypeType,
    DDLDataTypeBase64
};
enum DDLError {
    DDLErrorUnknown,
    DDLErrorUnexpectedToken,
    DDLErrorInvalidType,
    DDLErrorOutOfMemory,
    DDLErrorOutOfRange,
    DDLErrorUnexpectedEndOfFile,
    DDLErrorInvalidIdentifier,
    DDLErrorUnexpectedEndOfToken,
    DDLErrorInvalidData
};

struct DDLProp;
struct DDL;

enum DDLError DDL_getError();
char const* DDL_getErrorString();

struct DDL* DDL_create();
struct DDL* DDL_parseFromString(char const* ddlStr);
void DDL_free(struct DDL* ddl);

char const* DDL_getPropIdentifier(struct DDLProp* prop);
struct DDLProp* DDL_getPropNext(struct DDLProp* prop);

DDL_BOOL_T DDL_getPropBoolValue(struct DDLProp* prop, DDL_BOOL_T* outVal);
DDL_BOOL_T DDL_getPropInt8Value(struct DDLProp* prop, int8_t* outVal);
DDL_BOOL_T DDL_getPropInt16Value(struct DDLProp* prop, int16_t* outVal);
DDL_BOOL_T DDL_getPropInt32Value(struct DDLProp* prop, int32_t* outVal);
DDL_BOOL_T DDL_getPropInt64Value(struct DDLProp* prop, int64_t* outVal);
DDL_BOOL_T DDL_getPropUInt8Value(struct DDLProp* prop, uint8_t* outVal);
DDL_BOOL_T DDL_getPropUInt16Value(struct DDLProp* prop, uint16_t* outVal);
DDL_BOOL_T DDL_getPropUInt32Value(struct DDLProp* prop, uint32_t* outVal);
DDL_BOOL_T DDL_getPropUInt64Value(struct DDLProp* prop, uint64_t* outVal);
DDL_BOOL_T DDL_getPropHalfValue(struct DDLProp* prop, DDL_HALF_T* outVal);
DDL_BOOL_T DDL_getPropFloatValue(struct DDLProp* prop, float* outVal);
DDL_BOOL_T DDL_getPropDoubleValue(struct DDLProp* prop, double* outVal);
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char const** outVal);
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal);
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void const** outVal, int* outSize);

enum DDLStructType DDL_getStructType(struct DDL* struc);
DDL_BOOL_T DDL_isStructRoot(struct DDL* struc);
DDL_BOOL_T DDL_isStructDerived(struct DDL* struc);
DDL_BOOL_T DDL_isStructPrimitive(struct DDL* struc);

char const* DDL_getStructIdentifier(struct DDL* struc);
DDL_BOOL_T DDL_hasStructName(struct DDL* struc);
char const* DDL_getStructName(struct DDL* struc);
DDL_BOOL_T DDL_isStructNameGlobal(struct DDL* struc);
DDL_BOOL_T DDL_isStructNameLocal(struct DDL* struc);

int DDL_getStructPropCount(struct DDL* struc);
struct DDLProp* DDL_getStructPropStart(struct DDL* struc);
struct DDLProp* DDL_getStructPropByIndex(struct DDL* struc, int index);
struct DDLProp* DDL_findStructProp(struct DDL* struc, char const* propIdentifier);

struct DDL* DDL_getStructSiblingNext(struct DDL* struc);
struct DDL* DDL_getStructSiblingNextByIdentifier(struct DDL* struc, char const* id);

int DDL_getStructSubCount(struct DDL* struc);
struct DDL* DDL_getStructSubStart(struct DDL* struc);
struct DDL* DDL_getStructSubByIndex(struct DDL* struc, int index);
struct DDL* DDL_findStructSubByName(struct DDL* struc, char const* name);
struct DDL* DDL_findStructSubByIdentifier(struct DDL* struc, char const* id);

DDL_BOOL_T DDL_isStructDataFlat(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataArray(struct DDL* struc);
int DDL_getStructDataArraySize(struct DDL* struc);
DDL_BOOL_T DDL_hasStructDataStates(struct DDL* struc);
int DDL_getStructDataCount(struct DDL* struc);
struct DDLData* DDL_getStructDataStart(struct DDL* struc);
struct DDLData* DDL_getStructDataByIndex(struct DDL* struc, int index);

enum DDLDataType DDL_getStructDataType(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataBool(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt8(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt16(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt32(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt64(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt8(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt16(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt32(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt64(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataHalf(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataFloat(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataDouble(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataString(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataRef(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataType(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataBase64(struct DDL* struc);

DDL_BOOL_T DDL_getDataBoolValue(struct DDLData* data, DDL_BOOL_T* outVal);
DDL_BOOL_T DDL_getDataBoolArrayValue(struct DDLData* data, DDL_BOOL_T* outVal, int count);
DDL_BOOL_T DDL_getDataInt8Value(struct DDLData* data, int8_t* outVal);
DDL_BOOL_T DDL_getDataInt8ArrayValue(struct DDLData* data, int8_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt16Value(struct DDLData* data, int16_t* outVal);
DDL_BOOL_T DDL_getDataInt16ArrayValue(struct DDLData* data, int16_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt32Value(struct DDLData* data, int32_t* outVal);
DDL_BOOL_T DDL_getDataInt32ArrayValue(struct DDLData* data, int32_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt64Value(struct DDLData* data, int64_t* outVal);
DDL_BOOL_T DDL_getDataInt64ArrayValue(struct DDLData* data, int64_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt8Value(struct DDLData* data, uint8_t* outVal);
DDL_BOOL_T DDL_getDataUInt8ArrayValue(struct DDLData* data, uint8_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt16Value(struct DDLData* data, uint16_t* outVal);
DDL_BOOL_T DDL_getDataUInt16ArrayValue(struct DDLData* data, uint16_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt32Value(struct DDLData* data, uint32_t* outVal);
DDL_BOOL_T DDL_getDataUInt32ArrayValue(struct DDLData* data, uint32_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt64Value(struct DDLData* data, uint64_t* outVal);
DDL_BOOL_T DDL_getDataUInt64ArrayValue(struct DDLData* data, uint64_t* outVal, int count);
DDL_BOOL_T DDL_getDataHalfValue(struct DDLData* data, DDL_HALF_T* outVal);
DDL_BOOL_T DDL_getDataHalfArrayValue(struct DDLData* data, DDL_HALF_T* outVal, int count);
DDL_BOOL_T DDL_getDataFloatValue(struct DDLData* data, float* outVal);
DDL_BOOL_T DDL_getDataFloatArrayValue(struct DDLData* data, float* outVal, int count);
DDL_BOOL_T DDL_getDataDoubleValue(struct DDLData* data, double* outVal);
DDL_BOOL_T DDL_getDataDoubleArrayValue(struct DDLData* data, double* outVal, int count);
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char const** outVal);
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char const** outVal, int count);
DDL_BOOL_T DDL_getDataRefValue(struct DDLData* data, struct DDL** outVal);
DDL_BOOL_T DDL_getDataRefArrayValue(struct DDLData* data, struct DDL** outVal, int count);
DDL_BOOL_T DDL_getDataTypeValue(struct DDLData* data, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getDataTypeArrayValue(struct DDLData* data, enum DDLDataType* outVal, int count);
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void const** outVal, int* outSize);
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void const** outVal, int* outSizes, int count);

struct DDLData* DDL_getDataNext(struct DDLData* data);
struct DDLData* DDL_getDataNextByIdentifier(struct DDLData* data, char const* identifier);

//#define DDL_IMPLEMENTATION
#ifdef DDL_IMPLEMENTATION

#include <stdlib.h>
#include <string.h>

#ifndef DDL_CUSTOM_MATH
#include <math.h>
#define DDL_DPOW(num, exp) pow((num), (exp))
#endif

enum DDLPropStorageType {
    DDLPropStorageTypeInvalid,
    DDLPropStorageTypeRawString,
    DDLPropStorageTypeString,
    DDLPropStorageTypeRef,
    DDLPropStorageTypeType,
    DDLPropStorageTypeBase64
};

struct DDLProp {
    char* identifier;
    enum DDLPropStorageType storageType;
    char* value;
    size_t size;

    struct DDLProp* next;
};

struct DDLData {
    enum DDLDataType type;
    char* identifier;
    int size;
    void* data;
    struct DDLData* next;
};

struct DDLBase64Data {
    int size;
    void* data;
};

struct DDL {
    enum DDLStructType type;
    char* identifier;
    char* name;
    DDL_BOOL_T isNameGlobal;
    int dataArrayCount;
    enum DDLDataType dataType;
    DDL_BOOL_T isDataStates;
    
    int propCount;
    struct DDLProp* propStart;
    int subCount;
    struct DDL* subStart;
    int dataCount;
    struct DDLData* dataStart;

    struct DDL* next;
};

static enum DDLError global_error;
static char const* global_error_str;
enum DDLError DDL_getError() {
    return global_error;
}
char const* DDL_getErrorString() {
    return global_error_str;
}

void DDL_reportError(enum DDLError error) {
    global_error = error;
    switch(global_error) {
    case DDLErrorUnexpectedToken:
        global_error_str = "Unexpected token.";
        break;
    case DDLErrorInvalidType:
        global_error_str = "Unknown type.";
        break;
    case DDLErrorOutOfMemory:
        global_error_str = "Out of memory.";
        break;
    default:
        global_error_str = "Unknown.";
        break;
    }
}

uint32_t DDL_convertHalfBitsToFloatBits(uint16_t halfBits) {
    // Source:
    //  - J. van der Zijp, “Fast Half Float Conversions,” Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].

    uint32_t h = (uint32_t)halfBits;

    static uint32_t mantissatable[2028];
    static uint32_t offsettable[64];
    static uint32_t exponenttable[64];
    static DDL_BOOL_T init = DDL_FALSE;
    if(!init) {
        init = DDL_TRUE;

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
uint16_t DDL_convertFloatBitsToHalfBits(uint32_t floatBits) {
    // Source:
    //  - J. van der Zijp, “Fast Half Float Conversions,” Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].
    static uint16_t basetable[512];
    static uint8_t shifttable[512];
    static DDL_BOOL_T init = DDL_FALSE;
    if(!init) {
        init = DDL_TRUE;

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

struct DDL DDL_createStruct(enum DDLStructType structType) {
    return (struct DDL) {
        .type = structType,
        .identifier = DDL_NULL,
        .name = DDL_NULL,
        .isNameGlobal = DDL_FALSE,
        .dataArrayCount = 0,
        .dataType = DDLDataTypeInvalid,
        .isDataStates = DDL_FALSE,

        .propCount = 0,
        .propStart = DDL_NULL,
        .subCount = 0,
        .subStart = DDL_NULL,
        .dataCount = 0,
        .dataStart = DDL_NULL,

        .next = DDL_NULL
    };
}
struct DDL DDL_createRoot() {
    return DDL_createStruct(DDLStructTypeRoot);
}

struct DDLProp DDL_createProp() {
    return (struct DDLProp) {
        .identifier = DDL_NULL,
        .storageType = DDLPropStorageTypeInvalid,
        .value = DDL_NULL,
        .size = 0,
        .next = DDL_NULL
    };
}

struct DDL* DDL_create() {
    // Init if needed
    DDL_convertHalfBitsToFloatBits(0);

    struct DDL* root = (struct DDL*)malloc(sizeof(struct DDL));
    if(root == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_NULL;
    }
    *root = DDL_createRoot();
    return root;
}

DDL_BOOL_T DDL_isIdentifierDataType(char const* identifier) {
    return strcmp(identifier, "bool") == 0
        || strcmp(identifier, "b") == 0
        || strcmp(identifier, "int8") == 0
        || strcmp(identifier, "i8") == 0
        || strcmp(identifier, "int16") == 0
        || strcmp(identifier, "i16") == 0
        || strcmp(identifier, "int32") == 0
        || strcmp(identifier, "i32") == 0
        || strcmp(identifier, "int64") == 0
        || strcmp(identifier, "uint8") == 0
        || strcmp(identifier, "u8") == 0
        || strcmp(identifier, "uint16") == 0
        || strcmp(identifier, "u16") == 0
        || strcmp(identifier, "uint32") == 0
        || strcmp(identifier, "u32") == 0
        || strcmp(identifier, "uint64") == 0
        || strcmp(identifier, "u64") == 0
        || strcmp(identifier, "half") == 0
        || strcmp(identifier, "float16") == 0
        || strcmp(identifier, "h") == 0
        || strcmp(identifier, "f16") == 0
        || strcmp(identifier, "float") == 0
        || strcmp(identifier, "float32") == 0
        || strcmp(identifier, "f") == 0
        || strcmp(identifier, "f32") == 0
        || strcmp(identifier, "double") == 0
        || strcmp(identifier, "float64") == 0
        || strcmp(identifier, "d") == 0
        || strcmp(identifier, "f64") == 0
        || strcmp(identifier, "string") == 0
        || strcmp(identifier, "s") == 0
        || strcmp(identifier, "ref") == 0
        || strcmp(identifier, "r") == 0
        || strcmp(identifier, "type") == 0
        || strcmp(identifier, "t") == 0
        || strcmp(identifier, "base64") == 0
        || strcmp(identifier, "z") == 0;
}
enum DDLDataType DDL_convertIdentifierToDataType(char const* identifier) {
    if(strcmp(identifier, "bool") == 0
        || strcmp(identifier, "b") == 0) {
        return DDLDataTypeBool;
    }
    if(strcmp(identifier, "int8") == 0
        || strcmp(identifier, "i8") == 0) {
        return DDLDataTypeInt8;
    }
    if(strcmp(identifier, "int16") == 0
        || strcmp(identifier, "i16") == 0) {
        return DDLDataTypeInt16;
    }
    if(strcmp(identifier, "int32") == 0
        || strcmp(identifier, "i32") == 0) {
        return DDLDataTypeInt32;
    }
    if(strcmp(identifier, "int64") == 0
        || strcmp(identifier, "i64") == 0) {
        return DDLDataTypeInt64;
    }
    if(strcmp(identifier, "uint8") == 0
        || strcmp(identifier, "u8") == 0) {
        return DDLDataTypeUInt8;
    }
    if(strcmp(identifier, "uint16") == 0
        || strcmp(identifier, "u16") == 0) {
        return DDLDataTypeUInt16;
    }
    if(strcmp(identifier, "uint32") == 0
        || strcmp(identifier, "u32") == 0) {
        return DDLDataTypeUInt32;
    }
    if(strcmp(identifier, "uint64") == 0
        || strcmp(identifier, "u64") == 0) {
        return DDLDataTypeUInt64;
    }
    if(strcmp(identifier, "half") == 0
        || strcmp(identifier, "float16") == 0
        || strcmp(identifier, "h") == 0
        || strcmp(identifier, "f16") == 0) {
        return DDLDataTypeHalf;
    }
    if(strcmp(identifier, "float") == 0
        || strcmp(identifier, "float32") == 0
        || strcmp(identifier, "f") == 0
        || strcmp(identifier, "f32") == 0) {
        return DDLDataTypeFloat;
    }
    if(strcmp(identifier, "double") == 0
        || strcmp(identifier, "float64") == 0
        || strcmp(identifier, "d") == 0
        || strcmp(identifier, "f64") == 0) {
        return DDLDataTypeDouble;
    }
    if(strcmp(identifier, "string") == 0
        || strcmp(identifier, "s") == 0) {
        return DDLDataTypeString;
    }
    if(strcmp(identifier, "ref") == 0
        || strcmp(identifier, "r") == 0) {
        return DDLDataTypeRef;
    }
    if(strcmp(identifier, "type") == 0
        || strcmp(identifier, "t") == 0) {
        return DDLDataTypeType;
    }
    if(strcmp(identifier, "base64") == 0
        || strcmp(identifier, "z") == 0) {
        return DDLDataTypeBase64;
    }
    return DDLDataTypeInvalid;
}
DDL_BOOL_T DDL_isIdentifierReserved(char const* identifier) {
    if(DDL_isIdentifierDataType(identifier)) {
        return DDL_TRUE;
    }
    if(identifier[0] < 'a'
        || identifier[0] > 'z') {
        return DDL_FALSE;
    }
    int len = strlen(identifier);
    if(len == 1) {
        return DDL_FALSE;
    }
    for(int i = 1; i < len; i++) {
        if(identifier[i] < '0'
            || identifier[i] > '9') {
            return DDL_FALSE;
        }
    }
    return DDL_TRUE;
}

int DDL_skipWhitespace(char const* mem, int cursor) {
    for(;;cursor++) {
        switch(mem[cursor]) {
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            goto ddl_continue;

        default:
            return cursor;
        }

        ddl_continue:
            continue;
        ddl_break:
            break;
    }
    DDL_reportError(DDLErrorUnknown);
    return -1;
}
int DDL_skipWhitespaceAndComments(char const* mem, int cursor) {
    goto ddl_parse_current_char;
    for(;;cursor++) {
    ddl_parse_current_char:
        switch(mem[cursor]) {
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            goto ddl_continue1;
        
        case '/': // Potential comment
            if(mem[cursor + 1] != '\0') {
                if(mem[cursor + 1] == '/') {
                    // Confirmed, single-line
                    cursor++;
                    for(;;cursor++) {
                        switch(mem[cursor]) {
                        case '\n':
                        case '\r':
                        case '\0':
                            goto ddl_parse_current_char;

                        default:
                            break;
                        }
                    }
                }
                if(mem[cursor + 1] == '*') {
                    // Confirmed, multi-line
                    cursor++;
                    for(;;cursor++) {
                        switch(mem[cursor]) {
                        case '\0':
                            DDL_reportError(DDLErrorUnexpectedEndOfFile);
                            return -1;
                        case '/': // Potential end
                            if(mem[cursor - 1] == '*') {
                                // Confirmed.
                                cursor++;
                                goto ddl_parse_current_char;
                            }
                        default:
                            break;
                        }
                    }
                }
            }

        default:
            return cursor;
        }

        ddl_continue1:
            continue;
        ddl_break1:
            break;
    }
    DDL_reportError(DDLErrorUnknown);
    return -1;
}
int DDL_findEndOfToken(char const* mem, int cursor) {
    DDL_BOOL_T escaping = DDL_FALSE;
    DDL_BOOL_T inString = DDL_FALSE;
    DDL_BOOL_T wasString = DDL_FALSE;
    DDL_BOOL_T isString = DDL_FALSE;
    DDL_BOOL_T isChar = DDL_FALSE;
    for(;;cursor++) {
        char const c = mem[cursor];
        if(c == '\0') {
            if(inString) {
                DDL_reportError(DDLErrorUnexpectedEndOfFile);
                return -1;
            }
            return cursor;
        }

        if(c == '"') {
            if(!escaping) {
                if(inString) {
                    inString = DDL_FALSE;
                    cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
                    cursor--;
                    continue;
                } else {
                    wasString = isString = inString = DDL_TRUE;
                    continue;
                }
            }
        } else if(!isString && wasString) {
            DDL_reportError(DDLErrorUnexpectedToken);
            return -1;
        }

        if(c == ','
            || c == ')'
            || c == '}'
            || c == ' '
            || c == '\t'
            || c == '\n'
            || c == '\r') {
            return cursor;
        }

        if(escaping) {
            escaping = DDL_FALSE;
        } else {
            if(c == '\\') {
                escaping = DDL_TRUE;
            }
        }
    }
    DDL_reportError(DDLErrorUnknown);
    return -1;
}

DDL_BOOL_T DDL_parseStringAsIdentifier(char const* str,
    int n,
    char** outIdentifier,
    DDL_BOOL_T* outIsDataIdentifier) {
    int const start = 0;
    int cursor = 0;
    for(;cursor < n;cursor++) {
        if((str[cursor] >= 'A' && str[cursor] <= 'Z')
            || (str[cursor] >= 'a' && str[cursor] <= 'z')
            || str[cursor] == '_') {
            goto ddl_continue1;
        }
        if((str[cursor] >= '0'
            && str[cursor] <= '9')) {
            if(start == cursor) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            goto ddl_continue1;
        }

        switch(str[cursor]) {
        default:
            if(start == cursor) {
                DDL_reportError(DDLErrorUnexpectedToken);
                goto ddl_failure;
            }
            goto ddl_success;
        }

    ddl_continue1:
        continue;
    ddl_break1:
        break;
    }

ddl_success:
    if(outIdentifier != DDL_NULL) {
        *outIdentifier = (char*)malloc(cursor - start + 1);
        if(*outIdentifier == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            return -1;
        }
        strncpy(*outIdentifier, &str[start], cursor - start);
        (*outIdentifier)[cursor - start] = '\0';
    }
    if(outIsDataIdentifier != DDL_NULL) {
        *outIsDataIdentifier = DDL_isIdentifierDataType(*outIdentifier);
    }

    return DDL_TRUE;

DDL_reportError(DDLErrorUnknown);
ddl_failure:
    return DDL_FALSE;
}
int DDL_parseNextIdentifier(char const* mem,
    int cursor,
    char** outIdentifier,
    DDL_BOOL_T* outIsDataIdentifier) {
    int const start = cursor;
    int n = 0;
    int const strLen = strlen(mem);
    for(;; cursor++) {
        char const c = mem[cursor];
        if(c == '\0') {
            break;
        }
        if(c == '_'
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')) {
            n++;
            continue;
        }
        break;
    }
    if(DDL_parseStringAsIdentifier(&mem[start],
        n,
        outIdentifier,
        outIsDataIdentifier)) {
        return DDL_skipWhitespaceAndComments(mem, cursor);
    }
    return -1;
}
int DDL_parseNextName(char const* mem,
    int cursor,
    char** outName,
    DDL_BOOL_T* outIsGlobal) {
    int start = cursor;
    switch(mem[cursor++]) {
    case '$':
        *outIsGlobal = DDL_TRUE;
        break;
    case '%':
        *outIsGlobal = DDL_FALSE;
        break;
    case '\0':
        DDL_reportError(DDLErrorUnexpectedEndOfFile);
        return -1;
    default:
        DDL_reportError(DDLErrorUnexpectedToken);
        return -1;
    }

    return DDL_parseNextIdentifier(mem, cursor, outName, DDL_NULL); 
}

DDL_BOOL_T DDL_parseStringAsBool(char const* str, int n, DDL_BOOL_T* outVal) {
    if(n != 1 && (n != 4 || n != 5)) {
        return DDL_FALSE;
    }
    if(strncmp(str, "1", n) == 0
        || strncmp(str, "true", n) == 0) {
        if(outVal != DDL_NULL) {
            *outVal = DDL_TRUE;
        }
        return DDL_TRUE;
    } 
    if(strncmp(str, "0", n) == 0
        || strncmp(str, "false", n) == 0) {
        if(outVal != DDL_NULL) {
            *outVal = DDL_TRUE;
        }
        return DDL_TRUE;
    }
    return DDL_FALSE;
}
DDL_BOOL_T DDL_parseStringAsDecimalLiteral(char const* str, int n, uint64_t* outVal) {
    uint64_t num = 0;

    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    for(; cursor < strLen; cursor++) {
        char const c = str[cursor];
        if((c < '0' || c > '9')
            && c != '_') {
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }
        if(c == '_') {
            if(cursor == numBeg
                || str[cursor - 1] == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            continue;
        }
        // str[cursor] is on [0, 9]
        num *= 10;
        num += (uint64_t)(c - '0');
    }

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsHexLiteral(char const* str, int n, uint64_t* outVal) {
    uint64_t num = 0;

    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    // Literal must be at least 3 characters long, it is prepended by 0x/0X
    if((strLen - numBeg) < 3) {
        DDL_reportError(DDLErrorUnexpectedEndOfToken);
        return DDL_FALSE;
    }
    
    if(str[cursor] != '0') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;
    if(str[cursor] != 'x' && str[cursor] != 'X') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;

    int const hexBegin = cursor;

    for(; cursor < strLen; cursor++) {
        char c = str[cursor];
        if(c >= 'A' && c <= 'F') {
            c += 32; // Turn to owercase
        }
        if((c < '0' || c > '9')
            && (c < 'a' || c > 'f')
            && c != '_') {
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }
        if(c == '_') {
            if(cursor == hexBegin
                || str[cursor - 1] == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            continue;
        }

        num *= 16;
        if(c >= 'a' && c <= 'f') {
            c -= 87; // Bring down 'a' to 10, into its hex range
        } else {
            c -= '0';
        }
        num += c;
    }

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsOctalLiteral(char const* str, int n, uint64_t* outVal) {
    uint64_t num = 0;

    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    // Literal must be at least 3 characters long, it is prepended by 0o/0O
    if((strLen - numBeg) < 3) {
        DDL_reportError(DDLErrorUnexpectedEndOfToken);
        return DDL_FALSE;
    }
    
    if(str[cursor] != '0') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;
    if(str[cursor] != 'o' && str[cursor] != 'O') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;
    
    int const octalBegin = cursor;

    for(; cursor < strLen; cursor++) {
        char c = str[cursor];
        if((c < '0' || c > '7')
            && c != '_') {
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }
        if(c == '_') {
            if(cursor == octalBegin
                || str[cursor - 1] == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            continue;
        }

        num *= 8;
        num += (uint64_t)(c - '0');
    }

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsBinaryLiteral(char const* str, int n, uint64_t* outVal) {
    uint64_t num = 0;

    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    // Literal must be at least 3 characters long, it is prepended by 0b/0B
    if((strLen - numBeg) < 3) {
        DDL_reportError(DDLErrorUnexpectedEndOfToken);
        return DDL_FALSE;
    }
    
    if(str[cursor] != '0') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;
    if(str[cursor] != 'b' && str[cursor] != 'B') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;

    int const binaryBegin = cursor;

    for(; cursor < strLen; cursor++) {
        char c = str[cursor];
        if(c != '0'
            && c != '1'
            && c != '_') {
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }
        if(c == '_') {
            if(cursor == binaryBegin
                || str[cursor - 1] == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            continue;
        }

        num <<= 1;
        num |= (uint64_t)(c - '0');
    }

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsCharacterLiteral(char const* str, int n, uint64_t* outVal) {
    uint64_t num = 0;

    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    // Literal must be at least 3 characters long, it is a character surrounded by single-quotes
    if((strLen - numBeg) < 3) {
        DDL_reportError(DDLErrorUnexpectedEndOfToken);
        return DDL_FALSE;
    }
    
    if(str[cursor] != '\'') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;
    
    for(; cursor < strLen; cursor++) {
        char c = str[cursor];
        switch(c) {
        case '\\':
            if(++cursor >= strLen) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            switch(str[cursor]) {
            case 'a':
                c = '\a';
                goto ddl_add_char;
            case 'b':
                c = '\b';
                goto ddl_add_char;
            case 'f':
                c = '\f';
                goto ddl_add_char;
            case 'n':
                c = '\n';
                goto ddl_add_char;
            case 'r':
                c = '\r';
                goto ddl_add_char;
            case 't':
                c = '\t';
                goto ddl_add_char;
            case 'v':
                c = '\v';
                goto ddl_add_char;

            case '"':
            case '\'':
            case '\\':
            case '?':
            ddl_add_char:
                num *= 256;
                num += c;
                goto ddl_continue1;
            
            case 'x':
            {
                if((cursor + 2) >= strLen) {
                    DDL_reportError(DDLErrorUnexpectedEndOfToken);
                    return DDL_FALSE;
                }
                char x1 = str[cursor + 1];
                char x2 = str[cursor + 2];

                if(x1 >= 'A' || x1 <= 'F') {
                    x1 += 32; // Turn to lowercase
                }
                if((x1 < 'a' || x1 > 'f')
                    && (x1 < '0' || x1 > '9')) {
                    DDL_reportError(DDLErrorUnexpectedEndOfToken);
                    return DDL_FALSE;
                }
                if(x2 >= 'A' || x2 <= 'F') {
                    x2 += 32; // Turn to lowercase
                }
                if((x2 < 'a' || x2 > 'f')
                    && (x2 < '0' || x2 > '9')) {
                    DDL_reportError(DDLErrorUnexpectedEndOfToken);
                    return DDL_FALSE;
                }

                if(x1 >= 'a') {
                    x1 -= 87;
                }
                if(x1 >= '0') {
                    x1 -= '0';
                }
                if(x1 >= 'a') {
                    x2 -= 87;
                }
                if(x2 >= '0') {
                    x2 -= '0';
                }

                uint32_t byteVal = 0;
                byteVal |= x1;
                byteVal <<= 4;
                byteVal |= x2;

                num *= 256;
                num += byteVal;

                cursor += 2;
                goto ddl_continue1;
            }
            
            default:
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            break;
        case '\'':
            if(cursor + 1 < strLen) {
                DDL_reportError(DDLErrorUnexpectedEndOfToken);
                return DDL_FALSE;
            }
            goto ddl_success;
        default:
            if((c >= 0x20 && c <= 0x26)
                || (c >= 0x28 && c <= 0x5B)
                || (c >= 0x5D && c <= 0x7E)) {
                num *= 256;
                num += c;
                goto ddl_continue1;
            }
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }

        ddl_continue1:
            continue;
        ddl_break1:
            break;
    }
    DDL_reportError(DDLErrorUnexpectedEndOfToken);
    return DDL_FALSE;

ddl_success:

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsInteger(char const* str, int n, uint64_t* outVal) {
    // Figre out if this is a decimal, hex, octal, binary, or character literal
    if(n >= 3) {
        if(str[0] == '\'') {
            return DDL_parseStringAsDecimalLiteral(str, n, outVal);
        }
        if(str[0] == '0') {
            if(str[1] == 'x' || str[1] == 'X') {
                return DDL_parseStringAsHexLiteral(str, n, outVal);
            }
            if(str[1] == 'o' || str[1] == 'O') {
                return DDL_parseStringAsHexLiteral(str, n, outVal);
            }
            if(str[1] == 'b' || str[1] == 'B') {
                return DDL_parseStringAsHexLiteral(str, n, outVal);
            }
        }
    }
    return DDL_parseStringAsDecimalLiteral(str, n, outVal);
}
DDL_BOOL_T DDL_parseStringAsInt8(char const* str, int n, int8_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }
    int64_t inum = (int64_t)num;
    if(inum < -128 || inum > 127) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (int8_t)inum;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsInt16(char const* str, int n, int16_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    int64_t inum = (int64_t)num;
    if(inum < -32768 || inum > 32767) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (int16_t)inum;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsInt32(char const* str, int n, int32_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    int64_t inum = (int64_t)num;
    if(inum < -2147483648 || inum > 2147483647) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (int32_t)inum;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsInt64(char const* str, int n, int64_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (int64_t)num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsUInt8(char const* str, int n, uint8_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    if((num >> 8) > 0) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (uint8_t)num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsUInt16(char const* str, int n, uint16_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    if((num >> 16) > 0) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (uint16_t)num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsUInt32(char const* str, int n, uint32_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    if((num >> 32) > 0) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (uint32_t)num;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsUInt64(char const* str, int n, uint64_t* outVal) {
    uint64_t num;
    if(!DDL_parseStringAsInteger(str, n, &num)) {
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        *outVal = (uint64_t)num;
    }
    return DDL_TRUE;
}

DDL_BOOL_T DDL_parseStringAsFloatLiteral(char const* str, int n, double* outVal) {
    int cursor = 0;
    int const strLen = n;

    int const numBeg = (str[cursor] == '-' || str[cursor] == '+') ? 1 : 0;
    cursor = numBeg;

    double num = 0;
    double mul = 1;
    DDL_BOOL_T seenDecimal = DDL_FALSE;

    for(; cursor < strLen; cursor++) {
        char const c = str[cursor];
        if(c == '.') {
            seenDecimal = DDL_TRUE;
            continue;
        }
        if(c == 'e' || c == 'E') {
            break;
        }

        if((c < '0' || c > '9')
            && c != '_') {
            DDL_reportError(DDLErrorUnexpectedToken);
            return DDL_FALSE;
        }
        if(c == '_') {
            if(cursor == numBeg
                || str[cursor - 1] == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            continue;
        }
        // str[cursor] is on [0, 9]
        if(seenDecimal) {
            mul /= 10;
        }
        num *= 10;
        num += (c - '0');
    }
    num *= mul;
    if(str[cursor] == 'e' || str[cursor] == 'E') {
        cursor++;
        if(cursor >= strLen) {
            DDL_reportError(DDLErrorUnexpectedEndOfToken);
            return DDL_FALSE;
        }
        int expSign = 1;
        if(str[cursor] == '-') {
            expSign = -1;
        }
        if(str[cursor] == '-' || str[cursor] == '+') {
            cursor++;
            if(cursor >= strLen) {
                DDL_reportError(DDLErrorUnexpectedEndOfToken);
                return DDL_FALSE;
            }
        }
        int expBegin = cursor;
        double exp = 0;
        for(;cursor <= strLen;cursor++) {
            char const c = str[cursor];

            if((c < '0' || c > '9')
                && c != '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            if(c == '_') {
                if(cursor == expBegin
                    || str[cursor - 1] == '_') {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return DDL_FALSE;
                }
                continue;
            }
            // str[cursor] is on [0, 9]
            exp *= 10;
            exp += (c - '0');
        }
        exp *= expSign;
        num = DDL_DPOW(num, exp);
    }

    if(str[0] == '-') {
        num *= -1;
    }
    if(outVal != DDL_NULL) {
        *outVal = num;
    }
    return DDL_TRUE; 
}
DDL_BOOL_T DDL_parseStringAsDouble(char const* str, int n, double* outVal) {    
    // Can either be a float literal or a binary representation.
    int const floatBeg = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    int cursor = floatBeg;
    if(n - floatBeg >= 3) {
        if(str[cursor] == '0') {
            int literalType = str[cursor + 1];
            if(literalType == 'x' || literalType == 'X'
                || literalType == 'o' || literalType == 'O'
                || literalType == 'b' || literalType == 'B') {
                cursor += 2;
                uint64_t bits;
                if(!DDL_parseStringAsUInt64(&str[cursor], n - cursor, &bits)) {
                    return DDL_FALSE;
                }
                if(str[0] == '-') {
                    bits *= -1;
                }
                float f = *(float*)(&bits);
                if(outVal != DDL_NULL) {
                    *outVal = f;
                }
                return DDL_TRUE;
            }
        }
    }

    return DDL_parseStringAsFloatLiteral(str, n, outVal);
}
DDL_BOOL_T DDL_parseStringAsFloat(char const* str, int n, float* outVal) {    
    // Can either be a float literal or a binary representation.
    int const floatBeg = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    int cursor = floatBeg;
    if(n - floatBeg >= 3) {
        if(str[cursor] == '0') {
            int literalType = str[cursor + 1];
            if(literalType == 'x' || literalType == 'X'
                || literalType == 'o' || literalType == 'O'
                || literalType == 'b' || literalType == 'B') {
                cursor += 2;
                uint32_t bits;
                if(!DDL_parseStringAsUInt32(&str[cursor], n - cursor, &bits)) {
                    return DDL_FALSE;
                }
                if(str[0] == '-') {
                    bits *= -1;
                }
                float f = *(float*)(&bits);
                if(outVal != DDL_NULL) {
                    *outVal = f;
                }
                return DDL_TRUE;
            }
        }
    }

    double d;
    if(!DDL_parseStringAsFloatLiteral(str, n, &d)) {
        return DDL_FALSE;
    }
    if(outVal != DDL_NULL) {
        *outVal = (float)d;
    }

    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsHalf(char const* str, int n, DDL_HALF_T* outVal) {
    // Can either be a float literal or a binary representation.
    int const halfBeg = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    int cursor = halfBeg;
    if(n - halfBeg >= 3) {
        if(str[cursor] == '0') {
            int literalType = str[cursor + 1];
            if(literalType == 'x' || literalType == 'X'
                || literalType == 'o' || literalType == 'O'
                || literalType == 'b' || literalType == 'B') {
                cursor += 2;
                uint16_t bits;
                if(!DDL_parseStringAsUInt16(&str[cursor], n - cursor, &bits)) {
                    return DDL_FALSE;
                }
                if(str[0] == '-') {
                    bits *= -1;
                }
                if(sizeof(DDL_HALF_T) == 2) {
                    if(outVal != DDL_NULL) {
                        *outVal = *(DDL_HALF_T*)(&bits);
                    }
                } else {
                    if(outVal != DDL_NULL) {
                        uint32_t fBits = DDL_convertHalfBitsToFloatBits(bits);
                        *outVal = *(DDL_HALF_T*)(&fBits);
                    }
                }
                return DDL_TRUE;
            }
        }
    }

    double d;
    if(!DDL_parseStringAsFloatLiteral(str, n, &d)) {
        return DDL_FALSE;
    }

    if(sizeof(DDL_HALF_T) == 4) {
        if(outVal != DDL_NULL) {
            float f = (float)d;
            *outVal = *(DDL_HALF_T*)(&f);
        }
    } else {
        if(outVal != DDL_NULL) {
            float f = (float)d;
            uint16_t halfBits = DDL_convertFloatBitsToHalfBits(*(uint32_t*)&f);
            *outVal = *(DDL_HALF_T*)&halfBits;
        }
    }
    return DDL_TRUE;
}

DDL_BOOL_T DDL_parseStringAsString(char const* str, int n, char** outVal) {
    int cursor = 0;
    
    if(str[0] != '"') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return DDL_FALSE;
    }
    cursor++;

    char* buildStr = (char*)malloc(n * sizeof(char));
    int buildCursor = 0;
    for(; cursor < n; cursor++) {
        char c = str[cursor];
        switch(c) {
        case '\\':
            if(++cursor >= n) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            switch(str[cursor]) {
            case 'a':
                c = '\a';
                goto ddl_add_char;
            case 'b':
                c = '\b';
                goto ddl_add_char;
            case 'f':
                c = '\f';
                goto ddl_add_char;
            case 'n':
                c = '\n';
                goto ddl_add_char;
            case 'r':
                c = '\r';
                goto ddl_add_char;
            case 't':
                c = '\t';
                goto ddl_add_char;
            case 'v':
                c = '\v';
                goto ddl_add_char;

            case '"':
            case '\'':
            case '\\':
            case '?':
            ddl_add_char:
                buildStr[buildCursor++] = c;
                goto ddl_continue1;
            
            case 'x':
            case 'u':
            case 'U':
            {
                int numHexChars = 2;
                if(c == 'u') {
                    numHexChars = 4;
                }
                if(c == 'U') {
                    numHexChars = 6;
                }

                if((cursor + numHexChars) >= n) {
                    DDL_reportError(DDLErrorUnexpectedEndOfToken);
                    return DDL_FALSE;
                }

                uint32_t uniVal = 0;
                for(int i = numHexChars - 1; i >= 0; i++) {
                    char x = str[cursor++];
                    if(x >= 'A' || x <= 'F') {
                        x += 32; // Turn to lowercase
                    }
                    if((x < 'a' || x > 'f')
                        && (x < '0' || x > '9')) {
                        DDL_reportError(DDLErrorUnexpectedToken);
                        goto ddl_failure;
                    }
                    if(x >= 'a') {
                        x -= 87;
                    }
                    if(x >= '0') {
                        x -= '0';
                    }
                    
                    uniVal |= (x << i * 8);
                }

                // Check range
                if(uniVal < 0x000001 || uniVal > 0x10FFFF) {
                    DDL_reportError(DDLErrorOutOfRange);
                    goto ddl_failure;
                }

                // Turn into 8-bit characters to insert into string
                if(uniVal >= 0 && uniVal <= 0x7F) {
                    buildStr[buildCursor++] = uniVal & 0x7F;
                } else if(uniVal >= 80 && uniVal <= 0x7FF) {
                    buildStr[buildCursor++] = 0xC0 | (uniVal >> 6);
                    buildStr[buildCursor++] |= 0x80 | (uniVal & 0x3F);
                } else if(uniVal >= 800 && uniVal <= 0x7FFF) {
                    buildStr[buildCursor++] = 0xE0 | (uniVal >> 12);
                    buildStr[buildCursor++] |= 0x80 | ((uniVal >> 6) & 0x3F);
                    buildStr[buildCursor++] |= 0x80 | (uniVal & 0x3F);
                } else if(uniVal >= 10000 && uniVal <= 0x1FFFFF) {
                    buildStr[buildCursor++] = 0xF0 | (uniVal >> 18);
                    buildStr[buildCursor++] |= 0x80 | ((uniVal >> 12) & 0x3F);
                    buildStr[buildCursor++] |= 0x80 | ((uniVal >> 6) & 0x3F);
                    buildStr[buildCursor++] |= 0x80 | (uniVal & 0x3F);
                }

                goto ddl_continue1;
            }
            
            default:
                DDL_reportError(DDLErrorUnexpectedToken);
                return DDL_FALSE;
            }
            break;
        case '"':
            if(cursor + 1 < n) {
                // Search for next string
                cursor = DDL_skipWhitespaceAndComments(&str[cursor], cursor);

                if(cursor + 1 < n) {
                    if(str[cursor] != '"') {
                        DDL_reportError(DDLErrorUnexpectedEndOfToken);
                        return DDL_FALSE;
                    }
                }
            } else {
                goto ddl_success;
            }
        default:
            if(c < 0 // UTF-8 encoding
                || (c >= 0x20 && c <= 0x21)
                || (c >= 0x23 && c <= 0x5B)
                || (c >= 0x5D && c <= 0x7E)) {
                buildStr[buildCursor++] = c;
                goto ddl_continue1;
            }
            DDL_reportError(DDLErrorUnexpectedToken);
            goto ddl_failure;
        }
    ddl_continue1:
        continue;
    ddl_break1:
        break;
    }

    DDL_reportError(DDLErrorUnexpectedEndOfToken);
ddl_failure:
    free(buildStr);
    return DDL_FALSE;

ddl_success:
    buildStr[buildCursor++] = '\0';

    if(outVal != DDL_NULL) {
        *outVal = strdup(buildStr);
    }
    free(buildStr);
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsRef(char const* str, int n, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_parseStringAsType(char const* str, int n, enum DDLDataType* outVal) {
    char* identifier;
    DDL_BOOL_T isDataType;
    if(!DDL_parseStringAsIdentifier(str, n, &identifier, &isDataType)) {
        return DDL_FALSE;
    }
    if(!isDataType) {
        free(identifier);
        DDL_reportError(DDLErrorInvalidIdentifier);
        return DDL_FALSE;
    }
    if(outVal != DDL_NULL) {
        *outVal = DDL_convertIdentifierToDataType(identifier);
    }
    free(identifier);
    return DDL_TRUE;
}
DDL_BOOL_T DDL_parseStringAsBase64(char const* str, int n, uint8_t** outData, size_t* outDataSize) {
    // Pass 1, figure out the size of the binary data
    size_t charCount = 0;
    DDL_BOOL_T seenEqual = DDL_FALSE;
    for(int cursor = 0; cursor < n; cursor++) {
        char const c = str[cursor];
        switch(c) {
        case '\n':
        case '\r':
        case '\t':
        case ' ':
            continue;
        default:
            if(seenEqual) {
                // Next character must be an equal,
                // it must be the end, and we must be
                // dataSize % 4 == 3.
                if(c != '=' || cursor < n - 1 || charCount % 4 != 3) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    goto ddl_failure;
                }
            } else if((c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z')
            || (c >= '0' && c <= '0')
            || c == '+'
            || c == '/') {
                charCount++;
            } else if(c == '=') {
                seenEqual = DDL_TRUE;
                // We must be either dataSize % 4 == (3 || 2)
                if(charCount % 4 != 3 && charCount % 4 != 2) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    goto ddl_failure;
                }
                if(charCount % 4 == 3) {
                    // We must not be at the end, there has to be one more
                    if(cursor == n - 1) {
                        DDL_reportError(DDLErrorUnexpectedEndOfToken);
                        goto ddl_failure;
                    }
                } else { // dataSize % 4 == 2
                    // We must be at the end
                    if(cursor < n - 1) {
                        DDL_reportError(DDLErrorUnexpectedEndOfToken);
                        goto ddl_failure;
                    }
                }
            } else {
                DDL_reportError(DDLErrorUnexpectedToken);
                goto ddl_failure;
            }
            break;
        }
    }

    if(charCount % 4 == 1) {
        // Can only be 0, 2, or 3
        DDL_reportError(DDLErrorInvalidData);
        goto ddl_failure;
    }

    int const mod = (int)(charCount % 4);
    int dataSize = charCount / 4; // dataSize is now # of 4-letter groups
    dataSize *= 3; // dataSize is now # of bytes, except for those that got dropped (mod 2 or 3)
    dataSize += mod - 1; // If mod is 2, there is an extra byte. If mod is 3, there are two extra bytes.

    uint8_t* data = (uint8_t*)malloc(dataSize);
    if(data == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        goto ddl_failure;
    }

    int dataCursor = 0;
    uint8_t cs[4];
    int csCount = 0;
    for(int cursor = 0; cursor < n; cursor++) {
        char const c = str[cursor];
        switch(c) {
        case '\n':
        case '\r':
        case '\t':
        case ' ':
            continue;
        case '=':
            // We've already validated that the data is in proper form,
            // so we can stop.
            goto ddl_break1;
        
        default:
            {
                // We've already validated that the data is in proper form,
                // so we can just start processing.
                if(c >= 'A' && c <= 'Z') {
                    cs[csCount++] = c - 'A';
                } else if(c >= 'a' && c <= 'z') {
                    cs[csCount++] = c - 'a' + 26;
                } else if(c >= '0' && c <= '9') {
                    cs[csCount++] = c - '0' + 61;
                } else if(c == '+') {
                    cs[csCount++] = 62;
                } else if(c == '/') {
                    cs[csCount++] = 63;
                }
                if(csCount == 4) {
                    csCount = 0;
                    
                    data[dataCursor++] = ((cs[0] & 0x3F) << 2) | ((cs[1] & 0x30) >> 4);
                    data[dataCursor++] = ((cs[1] & 0xF) << 4) | ((cs[2] & 0xF0) >> 4);
                    data[dataCursor++] = ((cs[2] & 0x3) << 6) | ((cs[3] & 0x3F));
                }
                // If this is the last character, process.
                if(cursor == charCount - 1) {
                    if(mod == 2) {
                        data[dataCursor++] = ((cs[0] & 0x3F) << 2) | ((cs[1] & 0x30) >> 4);
                    }
                    if(mod == 3) {
                        data[dataCursor++] = ((cs[0] & 0x3F) << 2) | ((cs[1] & 0x30) >> 4);
                        data[dataCursor++] = ((cs[1] & 0xF) << 4) | ((cs[2] & 0x3C) >> 2);
                    }
                }
            }
            break;
        }
    ddl_continue1:
        continue;
    ddl_break1:
        break;
    }

    DDL_reportError(DDLErrorUnknown);
ddl_failure:
    if(data != DDL_NULL) {
        free(data);
    }
    return DDL_FALSE;
ddl_success:
    if(outData != DDL_NULL) {
        *outData = data;
    } else {
        free(data);
    }
    if(outDataSize != DDL_NULL) {
        *outDataSize = dataSize;
    }
    return DDL_TRUE;
}

int DDL_parseProps(char const* mem,
    int cursor,
    struct DDL* struc) {
    if(mem[cursor] != '(') {
        DDL_reportError(DDLErrorUnexpectedToken);
        return -1;
    }
    cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);

    struct DDLProp** propNext = &struc->propStart;

    char* currIdentifier = DDL_NULL;
    int currIdentifierLen;

    for(;;cursor++) {
        char const c = mem[cursor];
        switch(c) {
        case ',':
        case ')':
            {
                // No value, property value is a Bool `true`.
                struct DDLProp* prop = (struct DDLProp*)malloc(sizeof(struct DDLProp));
                *prop = DDL_createProp();
                prop->identifier = (char*)malloc((currIdentifierLen + 1) * sizeof(char));
                if(prop->identifier == DDL_NULL) {
                    DDL_reportError(DDLErrorOutOfMemory);
                    goto ddl_failure1;
                }

                strncpy(prop->identifier, currIdentifier, currIdentifierLen);
                prop->identifier[currIdentifierLen] = '\0';

                prop->storageType = DDLPropStorageTypeRawString;
                prop->value = strdup("1");
                if(prop->identifier == DDL_NULL) {
                    DDL_reportError(DDLErrorOutOfMemory);
                    free(prop);
                    goto ddl_failure1;
                }

                *propNext = prop;
                propNext = &prop->next;
                currIdentifier = DDL_NULL;

                cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
            }
            break;
        case '=':
            {
                // Property value assignment. Note that after the '=',
                // comments are allowed if the type is Base64 data. If it
                // is, there is guaranteed not to be any comments after
                // the '=', so we are okay to skip both whitespace and
                // comments without needing to know what type the property
                // is.
                cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
                int tokenStart = cursor;
                cursor = DDL_findEndOfToken(mem, cursor);
                int const tokenLen = cursor - tokenStart;

                struct DDLProp* prop = (struct DDLProp*)malloc(sizeof(struct DDLProp));
                *prop = DDL_createProp();
                prop->identifier = (char*)malloc((currIdentifierLen + 1) * sizeof(char));
                if(prop->identifier == DDL_NULL) {
                    DDL_reportError(DDLErrorOutOfMemory);
                    goto ddl_failure1;
                }

                strncpy(prop->identifier, currIdentifier, currIdentifierLen);
                prop->identifier[currIdentifierLen] = '\0';

                prop->storageType = DDLPropStorageTypeRawString;
                prop->value = malloc((cursor - tokenStart + 1) * sizeof(char));

                if(prop->value == DDL_NULL) {
                    DDL_reportError(DDLErrorOutOfMemory);
                    free(prop);
                    goto ddl_failure1;
                }
                strncpy((char*)prop->value, &mem[tokenStart], tokenLen);
                ((char*)prop->value)[tokenLen] = '\0';

                *propNext = prop;
                propNext = &prop->next;
                currIdentifier = DDL_NULL;

                cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
            }

        case '\0':
            DDL_reportError(DDLErrorUnexpectedEndOfFile);
            goto ddl_failure1;            
        default:
            currIdentifierLen = cursor;
            cursor = DDL_parseNextIdentifier(mem, cursor, &currIdentifier, DDL_NULL);
            currIdentifierLen = cursor - currIdentifierLen;
            if(cursor < 0) {
                return cursor;
            }
            if(DDL_isIdentifierReserved(currIdentifier)) {
                free(currIdentifier);
                DDL_reportError(DDLErrorInvalidIdentifier);
                goto ddl_failure1;
            }
            cursor = DDL_skipWhitespaceAndComments(mem, cursor);
        }
        
    ddl_continue1:
        continue;
    ddl_break1:
        break;
    ddl_failure1:
        if(currIdentifier != DDL_NULL) {
            free(currIdentifier);
        }
        return -1;
    }

    return DDL_skipWhitespaceAndComments(mem, cursor);
}
int DDL_parseNextStructure(char const* mem,
    int cursor,
    struct DDL** outStruc) {
    *outStruc = (struct DDL*)malloc(sizeof(struct DDL));
    if(*outStruc == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }
    **outStruc = DDL_createStruct(DDLStructTypeDerived); // Type doesn't matter

    // Identifier
    DDL_BOOL_T isDataIdentifier;
    cursor = DDL_parseNextIdentifier(mem,
        cursor,
        &(*outStruc)->identifier,
        &isDataIdentifier);
    if(cursor < 0) {
        goto ddl_failure;
    }
    
    if(isDataIdentifier) {
        (*outStruc)->type = DDLStructTypePrimitive;
        DDL_reportError(DDLErrorUnknown);
        goto ddl_failure;
    } else {
        (*outStruc)->type = DDLStructTypeDerived;
        DDL_BOOL_T skipName = DDL_FALSE;
        DDL_BOOL_T skipProp = DDL_FALSE;
        while(1) {
            switch(mem[cursor]) {
                case '$':
                case '%': // Name
                    if(skipName) {
                        DDL_reportError(DDLErrorUnexpectedToken);
                        goto ddl_failure;
                    }
                    skipName = DDL_TRUE;
                    cursor = DDL_parseNextName(mem,
                        cursor,
                        &(*outStruc)->name,
                        &(*outStruc)->isNameGlobal);
                    break;
                case '(': // Prop list
                    if(skipProp) {
                        DDL_reportError(DDLErrorUnexpectedToken);
                        goto ddl_failure;
                    }
                    skipProp = skipName = DDL_TRUE;
                    cursor = DDL_parseProps(mem, cursor, *outStruc);
                    break;
                case '{': // Structure body
                    cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
                    /*while(ddlStr[cursor] != '\0'
                        && ddlStr[cursor] != '}') {

                    }*/

                    if(mem[cursor] != '}') {
                        // @todo
                        DDL_reportError(DDLErrorUnknown); goto ddl_failure;
                    }
                    // Temporary for testing
                    cursor = cursor + 1;
                    goto ddl_end_of_struct;

                    break;

                case '\0':
                    DDL_reportError(DDLErrorUnexpectedEndOfFile);
                    goto ddl_failure;
                default:
                    DDL_reportError(DDLErrorUnexpectedToken);
                    goto ddl_failure;
            }
        }
    }

ddl_end_of_struct:
    return DDL_skipWhitespaceAndComments(mem, cursor); 

ddl_failure:
    DDL_free(*outStruc);
    *outStruc = DDL_NULL;
    return -1;
}
struct DDL* DDL_parseFromString(char const* ddlStr) {
    struct DDL* root = DDL_create();
    if(root == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_NULL;
    }

    int cursor = DDL_skipWhitespaceAndComments(ddlStr, 0);

    struct DDL** subNext = &root->subStart;
    while(ddlStr[cursor] != '\0') {
        struct DDL* subStruc = DDL_NULL;
        cursor = DDL_parseNextStructure(ddlStr, cursor, &subStruc);
        if(cursor < 0) {
            goto ddl_failure;
        }
        *subNext = subStruc;
        subNext = &subStruc->next;
        root->subCount++;
    }

    return root;

ddl_failure:
    DDL_free(root);
    return DDL_NULL;
}

void DDL_freeProp(struct DDLProp* prop) {
    if(prop == DDL_NULL) {
        return;
    }

    if(prop->identifier != DDL_NULL) {
        free(prop->identifier);
    }
    if(prop->value != DDL_NULL) {
        free(prop->value);
    }
    DDL_freeProp(prop->next);
    free(prop);
}
void DDL_freeData(struct DDLData* data) {
    if(data == DDL_NULL) {
        return;
    }

    if(data->identifier != DDL_NULL) {
        free(data->identifier);
    }
    if(data->data != DDL_NULL) {
        free(data->data);
    }
    DDL_freeData(data->next);
    free(data);
}
void DDL_free(struct DDL* ddl) {
    if(ddl == DDL_NULL) {
        return;
    }

    if(ddl->identifier != DDL_NULL) {
        free(ddl->identifier);
    }
    if(ddl->name != DDL_NULL) {
        free(ddl->name);
    }
    DDL_freeProp(ddl->propStart);
    DDL_freeData(ddl->dataStart);
    DDL_free(ddl->subStart);
    DDL_free(ddl->next);
    free(ddl);
}

char const* DDL_getPropIdentifier(struct DDLProp* prop) {
    return prop->identifier;
}
struct DDLProp* DDL_getPropNext(struct DDLProp* prop) {
    return prop->next;
}

DDL_BOOL_T DDL_getPropBoolValue(struct DDLProp* prop, DDL_BOOL_T* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsBool((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropInt8Value(struct DDLProp* prop, int8_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsInt8((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropInt16Value(struct DDLProp* prop, int16_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsInt16((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropInt32Value(struct DDLProp* prop, int32_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsInt32((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropInt64Value(struct DDLProp* prop, int64_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsInt64((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropUInt8Value(struct DDLProp* prop, uint8_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsUInt8((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropUInt16Value(struct DDLProp* prop, uint16_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsUInt16((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropUInt32Value(struct DDLProp* prop, uint32_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsUInt32((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropUInt64Value(struct DDLProp* prop, uint64_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsUInt64((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropHalfValue(struct DDLProp* prop, DDL_HALF_T* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsHalf((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropFloatValue(struct DDLProp* prop, float* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsFloat((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropDoubleValue(struct DDLProp* prop, double* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseStringAsDouble((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char const** outVal) {
    if(prop->storageType == DDLPropStorageTypeString) {
        if(outVal != DDL_NULL) {
            *outVal = (char const*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    if(!DDL_parseStringAsString((char*)prop->value, prop->size, (char**)&prop->value)) {
        return DDL_FALSE;
    }
    free(valuePtr);
    prop->storageType = DDLPropStorageTypeString;
    return DDL_getPropStringValue(prop, outVal);
}
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal) {
    if(prop->storageType == DDLPropStorageTypeType) {
        if(outVal != DDL_NULL) {
            *outVal = *(enum DDLDataType*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    enum DDLDataType* dataType = malloc(sizeof(enum DDLDataType)); 
    if(!DDL_parseStringAsType((char*)prop->value, prop->size, dataType)) {
        return DDL_FALSE;
    }
    free(valuePtr);
    prop->value = valuePtr;
    prop->storageType = DDLPropStorageTypeType;
    return DDL_getPropTypeValue(prop, outVal);
}
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void const** outVal, int* outSize) {
    if(prop->storageType == DDLPropStorageTypeType) {
        if(outVal != DDL_NULL) {
            *outVal = (enum DDLDataType*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    size_t dataSize;
    if(!DDL_parseStringAsBase64((char*)prop->value, prop->size, (uint8_t**)&prop->value, &dataSize)) {
        return DDL_FALSE;
    }
    free(valuePtr);
    prop->storageType = DDLPropStorageTypeBase64;
    prop->size = dataSize;
    return DDL_getPropBase64Value(prop, outVal, outSize);
}

enum DDLStructType DDL_getStructType(struct DDL* struc) {
    return struc->type;
}
DDL_BOOL_T DDL_isStructRoot(struct DDL* struc) {
    return struc->type == DDLStructTypeRoot;
}
DDL_BOOL_T DDL_isStructDerived(struct DDL* struc) {
    return struc->type == DDLStructTypeDerived;
}
DDL_BOOL_T DDL_isStructPrimitive(struct DDL* struc) {
    return struc->type == DDLStructTypePrimitive;
}

char const* DDL_getStructIdentifier(struct DDL* struc) {
    if(struc->identifier == DDL_NULL) {
        return "";
    }
    return struc->identifier;
}
DDL_BOOL_T DDL_hasStructName(struct DDL* struc) {
    return struc->name != DDL_NULL;
}
char const* DDL_getStructName(struct DDL* struc) {
    if(struc->name == DDL_NULL) {
        return "";
    }
    return struc->name;
}
DDL_BOOL_T DDL_isStructNameGlobal(struct DDL* struc) {
    return struc->isNameGlobal;
}
DDL_BOOL_T DDL_isStructNameLocal(struct DDL* struc) {
    return !struc->isNameGlobal;
}

int DDL_getStructPropCount(struct DDL* struc) {
    return struc->propCount;
}
struct DDLProp* DDL_getStructPropStart(struct DDL* struc) {
    return struc->propStart;
}
struct DDLProp* DDL_getStructPropByIndex(struct DDL* struc, int index) {
    int i = 0;
    struct DDLProp* prop = struc->propStart;
    do {
        if(prop == DDL_NULL) {
            return DDL_NULL;
        }
        prop = prop->next;
    }while(++i < index);
    return prop;
}
struct DDLProp* DDL_findStructProp(struct DDL* struc, char const* propIdentifier) {
    struct DDLProp* prop = struc->propStart;
    while(prop != DDL_NULL) {
        if(strcmp(prop->identifier, propIdentifier) == 0) {
            return prop;
        }
        prop = prop->next;
    }
    return DDL_NULL;
}

struct DDL* DDL_getStructSiblingNext(struct DDL* struc) {
    return struc->next;
}
struct DDL* DDL_getStructSiblingNextByIdentifier(struct DDL* struc, char const* id) {
    while(struc != DDL_NULL) {
        if(strcmp(struc->identifier, id) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    return DDL_NULL;
}

int DDL_getStructSubCount(struct DDL* struc) {
    return struc->subCount;
}
struct DDL* DDL_getStructSubStart(struct DDL* struc) {
    return struc->subStart;
}
struct DDL* DDL_getStructSubByIndex(struct DDL* struc, int index) {
    struct DDL* sub = struc->subStart;
    int i = 0;
    do {
        if(sub == DDL_NULL) {
            return DDL_NULL;
        }
        sub = sub->next;
    } while(++i < index);
    return sub;
}
struct DDL* DDL_findStructSubByName(struct DDL* struc, char const* name) {
    struct DDL* sub = struc->subStart;
    while(sub != DDL_NULL) {
        if(strcmp(sub->name, name) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return DDL_NULL;
}
struct DDL* DDL_findStructSubByIdentifier(struct DDL* struc, char const* id) {
    struct DDL* sub = struc->subStart;
    while(sub != DDL_NULL) {
        if(strcmp(sub->identifier, id) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return DDL_NULL;
}

DDL_BOOL_T DDL_isStructDataFlat(struct DDL* struc) {
    return struc->dataArrayCount == 0;
}
DDL_BOOL_T DDL_isStructDataArray(struct DDL* struc) {
    return struc->dataArrayCount > 0;
}
int DDL_getStructDataArraySize(struct DDL* struc) {
    return struc->dataArrayCount;
}
DDL_BOOL_T DDL_hasStructDataStates(struct DDL* struc) {
    return struc->isDataStates;
}
int DDL_getStructDataCount(struct DDL* struc) {
    return struc->dataCount;
}
struct DDLData* DDL_getStructDataStart(struct DDL* struc) {
    return struc->dataStart;
}
struct DDLData* DDL_getStructDataByIndex(struct DDL* struc, int index) {
    struct DDLData* data = struc->dataStart;
    int i = 0;
    do {
        if(data == DDL_NULL) {
            return DDL_NULL;
        }
        data = data->next;
    } while(++i < index);
    return data;
}

enum DDLDataType DDL_getStructDataType(struct DDL* struc) {
    return struc->dataType;
}
DDL_BOOL_T DDL_isStructDataBool(struct DDL* struc) {
    return struc->dataType == DDLDataTypeBool;
}
DDL_BOOL_T DDL_isStructDataInt8(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt8;
}
DDL_BOOL_T DDL_isStructDataInt16(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt16;
}
DDL_BOOL_T DDL_isStructDataInt32(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt32;
}
DDL_BOOL_T DDL_isStructDataInt64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt64;
}
DDL_BOOL_T DDL_isStructDataUInt8(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt8;
}
DDL_BOOL_T DDL_isStructDataUInt16(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt16;
}
DDL_BOOL_T DDL_isStructDataUInt32(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt32;
}
DDL_BOOL_T DDL_isStructDataUInt64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt64;
}
DDL_BOOL_T DDL_isStructDataHalf(struct DDL* struc) {
    return struc->dataType == DDLDataTypeHalf;
}
DDL_BOOL_T DDL_isStructDataFloat(struct DDL* struc) {
    return struc->dataType == DDLDataTypeFloat;
}
DDL_BOOL_T DDL_isStructDataDouble(struct DDL* struc) {
    return struc->dataType == DDLDataTypeDouble;
}
DDL_BOOL_T DDL_isStructDataString(struct DDL* struc) {
    return struc->dataType == DDLDataTypeString;
}
DDL_BOOL_T DDL_isStructDataRef(struct DDL* struc) {
    return struc->dataType == DDLDataTypeRef;
}
DDL_BOOL_T DDL_isStructDataType(struct DDL* struc) {
    return struc->dataType == DDLDataTypeType;
}
DDL_BOOL_T DDL_isStructDataBase64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeBase64;
}

DDL_BOOL_T DDL_getDataBoolValue(struct DDLData* data, DDL_BOOL_T* outVal) {
    if(data->type != DDLDataTypeBool) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_BOOL_T*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBoolArrayValue(struct DDLData* data, DDL_BOOL_T* outVal, int count) {
    if(data->type != DDLDataTypeBool) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(DDL_BOOL_T);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((DDL_BOOL_T*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt8Value(struct DDLData* data, int8_t* outVal) {
    if(data->type != DDLDataTypeInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt8ArrayValue(struct DDLData* data, int8_t* outVal, int count) {
    if(data->type != DDLDataTypeInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int8_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt16Value(struct DDLData* data, int16_t* outVal) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int16_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt16ArrayValue(struct DDLData* data, int16_t* outVal, int count) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int16_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt32Value(struct DDLData* data, int32_t* outVal) {
    if(data->type != DDLDataTypeInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int32_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt32ArrayValue(struct DDLData* data, int32_t* outVal, int count) {
    if(data->type != DDLDataTypeInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int32_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int32_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt64Value(struct DDLData* data, int64_t* outVal) {
    if(data->type != DDLDataTypeInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int64_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt64ArrayValue(struct DDLData* data, int64_t* outVal, int count) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt8Value(struct DDLData* data, uint8_t* outVal) {
    if(data->type != DDLDataTypeUInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt8ArrayValue(struct DDLData* data, uint8_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint8_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt16Value(struct DDLData* data, uint16_t* outVal) {
    if(data->type != DDLDataTypeUInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint16_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt16ArrayValue(struct DDLData* data, uint16_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint16_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt32Value(struct DDLData* data, uint32_t* outVal) {
    if(data->type != DDLDataTypeUInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint32_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt32ArrayValue(struct DDLData* data, uint32_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint32_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint32_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt64Value(struct DDLData* data, uint64_t* outVal) {
    if(data->type != DDLDataTypeUInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint64_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt64ArrayValue(struct DDLData* data, uint64_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint64_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint64_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataHalfValue(struct DDLData* data, DDL_HALF_T* outVal) {
    if(data->type != DDLDataTypeHalf) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_HALF_T*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataHalfArrayValue(struct DDLData* data, DDL_HALF_T* outVal, int count) {
    if(data->type != DDLDataTypeHalf) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(DDL_HALF_T);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((DDL_HALF_T*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataFloatValue(struct DDLData* data, float* outVal) {
    if(data->type != DDLDataTypeFloat) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(float*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataFloatArrayValue(struct DDLData* data, float* outVal, int count) {
    if(data->type != DDLDataTypeFloat) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(float);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((float*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataDoubleValue(struct DDLData* data, double* outVal) {
    if(data->type != DDLDataTypeDouble) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(double*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataDoubleArrayValue(struct DDLData* data, double* outVal, int count) {
    if(data->type != DDLDataTypeDouble) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(double);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((double*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char const** outVal) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    if(outVal != DDL_NULL) {
        *outVal = (char*)data->data;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char const** outVal, int count) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores string count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    char const* strStart = (char*)data->data;

    if(outVal != DDL_NULL) {
        outVal[0] = strStart;
        for(int i = 1; i < count; i++) {
            strStart = strStart + strlen(strStart) + 2;
            outVal[i] = strStart;
        }
    }

    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataRefValue(struct DDLData* data, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getDataRefArrayValue(struct DDLData* data, struct DDL** outVal, int count) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getDataTypeValue(struct DDLData* data, enum DDLDataType* outVal) {
    if(data->type != DDLDataTypeType) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(enum DDLDataType*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataTypeArrayValue(struct DDLData* data, enum DDLDataType* outVal, int count) {
    if(data->type != DDLDataTypeType) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(enum DDLDataType);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((enum DDLDataType*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void const** outVal, int* outSize) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    struct DDLBase64Data* base64Data = (struct DDLBase64Data*)data->data;

    if(outVal != DDL_NULL) {
        if(outSize == DDL_NULL) {
            DDL_reportError(DDLErrorUnknown);
            return DDL_FALSE;
        }
        *outVal = base64Data->data;
        *outSize = base64Data->size;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void const** outVal, int* outSizes, int count) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores blob count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        if(outSizes == DDL_NULL) {
            DDL_reportError(DDLErrorUnknown);
            return DDL_FALSE;
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
    return DDL_TRUE;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* DDL_H */
