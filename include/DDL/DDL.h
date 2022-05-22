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
    DDLErrorUnexpectedEndOfFile
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

enum DDLDataType DDL_getPropType(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropBool(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropInt8(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropInt16(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropInt32(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropInt64(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropUInt8(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropUInt16(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropUInt32(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropUInt64(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropHalf(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropFloat(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropDouble(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropString(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropRef(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropType(struct DDLProp* prop);
DDL_BOOL_T DDL_isPropBase64(struct DDLProp* prop);

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
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char** outVal);
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal);
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void** outVal, int* outSize);

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
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char** outVal);
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char** outVal, int count);
DDL_BOOL_T DDL_getDataRefValue(struct DDLData* data, struct DDL** outVal);
DDL_BOOL_T DDL_getDataRefArrayValue(struct DDLData* data, struct DDL** outVal, int count);
DDL_BOOL_T DDL_getDataTypeValue(struct DDLData* data, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getDataTypeArrayValue(struct DDLData* data, enum DDLDataType* outVal, int count);
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void** outVal, int* outSize);
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void** outVal, int* outSizes, int count);

struct DDLData* DDL_getDataNext(struct DDLData* data);
struct DDLData* DDL_getDataNextByIdentifier(struct DDLData* data, char const* identifier);

//#define DDL_IMPLEMENTATION
#ifdef DDL_IMPLEMENTATION
#include <stdlib.h>
#include <string.h>

struct DDLProp {
    enum DDLDataType type;
    char* identifier;
    void* value;

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

struct DDL* DDL_create() {
    struct DDL* root = (struct DDL*)malloc(sizeof(struct DDL));
    if(root == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_NULL;
    }
    *root = DDL_createRoot();
    return root;
}

// enum DDLToken {
//     DDLTokenStructure,
//     DDLTokenIdentifier,
//     DDLTokenName,
//     DDLTokenProperty,
//     DDLTokenDataType,
//     DDLTokenDataList,
//     DDLTokenIntegerLiteral,
//     DDLTokenDataArrayList,

// };
struct DDL_token {
    int start;
    int end;
};

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
    for(;;cursor++) {
    ddl_parse_current_char:
        switch(mem[cursor]) {
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            goto ddl_continue1;
        
        case '/': // Potential single-line comment
            if(mem[cursor + 1] != '\0'
                && mem[cursor + 1] == '/') {
                // Confirmed
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

                ddl_continue2:
                    continue;
                ddl_break2:
                    break;
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
int DDL_parseNextIdentifier(char const* mem,
    int cursor,
    char** outIdentifier,
    DDL_BOOL_T* outIsDataIdentifier) {
    int start = cursor;
    for(;;cursor++) {
        if((mem[cursor] >= 'A' && mem[cursor] <= 'Z')
            || (mem[cursor] >= 'a' && mem[cursor] <= 'z')
            || mem[cursor] == '_') {
            goto ddl_continue1;
        }
        if((mem[cursor] >= '0'
            && mem[cursor] <= '9')) {
            if(start == cursor) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            goto ddl_continue1;
        }

        switch(mem[cursor]) {
        default:
            if(start == cursor) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            goto ddl_success;
        }

    ddl_continue1:
        continue;
    ddl_break1:
        break;
    }

    DDL_reportError(DDLErrorUnknown);
    return -1;

ddl_success:
    *outIdentifier = (char*)malloc(cursor - start + 1);
    if(*outIdentifier == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }
    strncpy(*outIdentifier, &mem[start], cursor - start);
    (*outIdentifier)[cursor - start] = '\0';
    if(outIsDataIdentifier != DDL_NULL) {
        *outIsDataIdentifier = DDL_isIdentifierDataType(*outIdentifier);
    }

    return DDL_skipWhitespaceAndComments(mem, cursor);
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
                    cursor = DDL_skipWhitespaceAndComments(mem, cursor + 1);
                    // @todo
                    DDL_reportError(DDLErrorUnknown); goto ddl_failure;
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
    if(prop->identifier != DDL_NULL) {
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

enum DDLDataType DDL_getPropType(struct DDLProp* prop) {
    return prop->type;
}
DDL_BOOL_T DDL_isPropBool(struct DDLProp* prop) {
    return prop->type == DDLDataTypeBool;
}
DDL_BOOL_T DDL_isPropInt8(struct DDLProp* prop) {
    return prop->type == DDLDataTypeInt8;
}
DDL_BOOL_T DDL_isPropInt16(struct DDLProp* prop) {
    return prop->type == DDLDataTypeInt16;
}
DDL_BOOL_T DDL_isPropInt32(struct DDLProp* prop) {
    return prop->type == DDLDataTypeInt32;
}
DDL_BOOL_T DDL_isPropInt64(struct DDLProp* prop) {
    return prop->type == DDLDataTypeInt64;
}
DDL_BOOL_T DDL_isPropUInt8(struct DDLProp* prop) {
    return prop->type == DDLDataTypeUInt8;
}
DDL_BOOL_T DDL_isPropUInt16(struct DDLProp* prop) {
    return prop->type == DDLDataTypeUInt16;
}
DDL_BOOL_T DDL_isPropUInt32(struct DDLProp* prop) {
    return prop->type == DDLDataTypeUInt32;
}
DDL_BOOL_T DDL_isPropUInt64(struct DDLProp* prop) {
    return prop->type == DDLDataTypeUInt64;
}
DDL_BOOL_T DDL_isPropHalf(struct DDLProp* prop) {
    return prop->type == DDLDataTypeHalf;
}
DDL_BOOL_T DDL_isPropFloat(struct DDLProp* prop) {
    return prop->type == DDLDataTypeFloat;
}
DDL_BOOL_T DDL_isPropDouble(struct DDLProp* prop) {
    return prop->type == DDLDataTypeDouble;
}
DDL_BOOL_T DDL_isPropString(struct DDLProp* prop) {
    return prop->type == DDLDataTypeString;
}
DDL_BOOL_T DDL_isPropRef(struct DDLProp* prop) {
    return prop->type == DDLDataTypeRef;
}
DDL_BOOL_T DDL_isPropType(struct DDLProp* prop) {
    return prop->type == DDLDataTypeType;
}
DDL_BOOL_T DDL_isPropBase64(struct DDLProp* prop) {
    return prop->type == DDLDataTypeBase64;
}

DDL_BOOL_T DDL_getPropBoolValue(struct DDLProp* prop, DDL_BOOL_T* outVal) {
    if(prop->type != DDLDataTypeBool) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_BOOL_T*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropInt8Value(struct DDLProp* prop, int8_t* outVal) {
    if(prop->type != DDLDataTypeInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int8_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropInt16Value(struct DDLProp* prop, int16_t* outVal) {
    if(prop->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int16_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropInt32Value(struct DDLProp* prop, int32_t* outVal) {
    if(prop->type != DDLDataTypeInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int32_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropInt64Value(struct DDLProp* prop, int64_t* outVal) {
    if(prop->type != DDLDataTypeInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int64_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropUInt8Value(struct DDLProp* prop, uint8_t* outVal) {
    if(prop->type != DDLDataTypeUInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint8_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropUInt16Value(struct DDLProp* prop, uint16_t* outVal) {
    if(prop->type != DDLDataTypeUInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint16_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropUInt32Value(struct DDLProp* prop, uint32_t* outVal) {
    if(prop->type != DDLDataTypeUInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint32_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropUInt64Value(struct DDLProp* prop, uint64_t* outVal) {
    if(prop->type != DDLDataTypeUInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint64_t*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropHalfValue(struct DDLProp* prop, DDL_HALF_T* outVal) {
    if(prop->type != DDLDataTypeHalf) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_HALF_T*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropFloatValue(struct DDLProp* prop, float* outVal) {
    if(prop->type != DDLDataTypeFloat) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(float*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropDoubleValue(struct DDLProp* prop, double* outVal) {
    if(prop->type != DDLDataTypeDouble) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(double*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char** outVal) {
    if(prop->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = (char*)malloc((strlen((char*)prop->value)+1) * sizeof(char));
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    strcpy(*outVal, (char*)prop->value);
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal) {
    if(prop->type != DDLDataTypeType) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(enum DDLDataType*)prop->value;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void** outVal, int* outSize) {
    if(prop->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    struct DDLBase64Data* data = (struct DDLBase64Data*)prop->value;
    *outVal = malloc(data->size);
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    memcpy(*outVal, data->data, data->size);
    return DDL_TRUE;
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
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char** outVal) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = (char*)malloc((strlen((char*)data->data)+1) * sizeof(char));
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    strcpy(*outVal, (char*)data->data);
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char** outVal, int count) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores string count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    
    char* dupStrs[count];

    size_t copyLen = 0;

    // Figure out how much memory to copy
    char* strStart = (char*)data->data;
    for(int i = 0; i < count; i++) {
        size_t strLen = strlen(strStart);
        copyLen += strLen + 1;
        strStart += strLen + 1;
    }
    *outVal = (char*)malloc(copyLen);
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    memcpy(*outVal, data->data, copyLen);
    strStart = *outVal;
    strStart += strlen(strStart) + 1; // Skip past first string
    for(int i = 1; i < count; i++) {
        outVal[i] = strStart;
        if(i < count - 1) {
            strStart += strlen(strStart) + 1;
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
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void** outVal, int* outSize) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    struct DDLBase64Data* base64Data = (struct DDLBase64Data*)data->data;
    *outVal = malloc(base64Data->size);
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    memcpy(*outVal, base64Data->data, base64Data->size);
    *outSize = base64Data->size;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void** outVal, int* outSizes, int count) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores blob count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    
    uint8_t* dataStart = (uint8_t*)data->data;
    size_t memRequired = 0;
    for(int i = 0; i < count; i++) {        
        // First sizeof(uint64_t) bytes store size of blob after it, in bytes
        uint64_t blobSize = ((uint64_t*)dataStart)[0];
        memRequired += blobSize;
        dataStart += sizeof(uint64_t) + blobSize;
    }
    *outVal = malloc(memRequired);
    if(*outVal == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_FALSE;
    }
    dataStart = (uint8_t*)data->data;
    size_t memCopied = 0;
    for(int i = 0; i < count; i++) {
        // First sizeof(uint64) bytes store size of blob after it, in bytes
        uint64_t blobSize = ((uint64_t*)dataStart)[0];
        dataStart += sizeof(uint64_t);
        if(i > 0) {
            outVal[i] = *((uint8_t**)(outVal)) + memCopied;
        }
        memcpy(outVal[i], dataStart, blobSize);
        memCopied += blobSize;
        dataStart += blobSize;
    }
    return DDL_TRUE;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* DDL_H */
