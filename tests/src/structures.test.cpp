#include <catch2/catch.hpp>

#include <DDL/DDL.h>

#include <stdio.h>

TEST_CASE("Test case", "[tests]") {
    char* ddlBuf = 0;
    long length;
    FILE* f = fopen("/Users/philiprader/Developer/Git/DDL/tests/resources/Structs.ddl", "rb"); 
    if(f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        ddlBuf = (char*)malloc(length + 1);
        if(ddlBuf) {
            fread(ddlBuf, 1, length, f);
        }
        fclose(f);
    }
    REQUIRE(ddlBuf != 0);
    ddlBuf[length] = '\0';

    struct DDL* ddl = DDL_parseFromString(ddlBuf);
    REQUIRE(ddl != DDL_NULL);
    struct DDL* struc1 = DDL_getStructSubStart(ddl);
    REQUIRE(DDL_getStructPropCount(struc1) == 1);
    DDL_BOOL_T propVal;
    REQUIRE(DDL_getPropBoolValue(DDL_getStructPropStart(struc1), &propVal));
    REQUIRE(propVal);
    DDL_free(ddl);
}