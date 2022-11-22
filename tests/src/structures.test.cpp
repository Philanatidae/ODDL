#include <catch2/catch.hpp>

#include <ODDL/ODDL.h>

#include <stdio.h>

TEST_CASE("Test case", "[tests]") {
    char* ddlBuf = 0;
    long length;
    char const* ddlFile = "./tests/resources/Structs.ddl";
    FILE* f = fopen(ddlFile, "rb");
    REQUIRE(f != 0);
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

    struct ODDL* ddl = ODDL_parseFromString(ddlBuf);
    REQUIRE(ddl != ODDL_NULL);
    struct ODDL* struc1 = ODDL_getStructSubStart(ddl);
    REQUIRE(ODDL_getStructPropCount(struc1) == 1);
    ODDL_BOOL_T propVal;
    REQUIRE(ODDL_getPropBoolValue(ODDL_getStructPropStart(struc1), &propVal));
    REQUIRE(propVal);
    ODDL_free(ddl);
}
