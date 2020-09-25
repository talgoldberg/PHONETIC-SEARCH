/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *AUTHORS: Avichai and Tal
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b or p and f") {
    string text = "xxx happy yyy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
            CHECK(find(text, "haffy") == string("happy"));
            CHECK(find(text, "hafby") == string("happy"));
            CHECK(find(text, "hapfy") == string("happy"));
            CHECK(find(text, "hafpy") == string("happy"));
    }

TEST_CASE("space tests") {
    string text = "     happy";
    string text1 = "   happy     ";
    string text2 = "  happy   ";
    string text3 = "happy";
            CHECK(find(text1, "happy") == string("happy"));
            CHECK(find(text2, "happy") == string("happy"));
            CHECK(find(text, "happy") == string("happy"));

            CHECK(find(text3, "happy    ") == string("happy"));
            CHECK(find(text3, "   happy") == string("happy"));

}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    string text1 = "IRONman xxx yyy";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
            CHECK(find(text1, "IRONman") == string("IRONman"));
            CHECK(find(text1, "IRONMaN") == string("IRONman"));
            CHECK(find(text1, "irONman") == string("IRONman"));
            CHECK(find(text1, "ironMAN") == string("IRONman"));
            CHECK(find(text1, "IrOnMaN") == string("IRONman"));

}
TEST_CASE("Test replacement of i and y") {
    string text = "xxx hii yyy";
            CHECK(find(text, "hyy") == string("hii"));
            CHECK(find(text, "hiy") == string("hii"));
            CHECK(find(text, "hyi") == string("hii"));
            CHECK(find(text, "hii") == string("hii"));


}


TEST_CASE("Test replacement of s and z") {
    string text = "xxx Suzuki yyy";
            CHECK(find(text, "zuzuki") == string("Suzuki"));
            CHECK(find(text, "susuki") == string("Suzuki"));
            CHECK(find(text, "Zusuki") == string("Suzuki"));
            CHECK(find(text, "zusuki") == string("Suzuki"));
            CHECK(find(text, "Zuzuki") == string("Suzuki"));
            CHECK(find(text, "Susuki") == string("Suzuki"));

}

TEST_CASE("Test replacement of c and k or c and q or k and q") {
    string text = "checq yyy";
            CHECK(find(text, "check") == string("checq"));
            CHECK(find(text, "kheck") == string("checq"));
            CHECK(find(text, "qhekq") == string("checq"));
            CHECK(find(text, "qhecq") == string("checq"));
            CHECK(find(text, "cheqc") == string("checq"));
            CHECK(find(text, "qheqq") == string("checq"));
            CHECK(find(text, "checc") == string("checq"));
            CHECK(find(text, "khekk") == string("checq"));
}

TEST_CASE("Test replacement of j and g or o and u or both") {
    string text = "google xxx yyy";
            CHECK(find(text, "joojle") == string("google"));
            CHECK(find(text, "joogle") == string("google"));
            CHECK(find(text, "goojle") == string("google"));
            CHECK(find(text, "guugle") == string("google"));
            CHECK(find(text, "gougle") == string("google"));
            CHECK(find(text, "guogle") == string("google"));
            CHECK(find(text, "juujle") == string("google"));
            CHECK(find(text, "juogle") == string("google"));
            CHECK(find(text, "goujle") == string("google"));
            CHECK(find(text, "jougle") == string("google"));
    string text1 = "xxx jongle yyy";
            CHECK(find(text1, "jungle") == string("jongle"));
            CHECK(find(text1, "jonjle") == string("jongle"));
            CHECK(find(text1, "gungle") == string("jongle"));
            CHECK(find(text1, "gongle") == string("jongle"));
            CHECK(find(text1, "gunjle") == string("jongle"));
            CHECK(find(text1, "jongle") == string("jongle"));
            CHECK(find(text1, "junjle") == string("jongle"));
            CHECK(find(text1, "JUngle") == string("jongle"));
            CHECK(find(text1, "jOngle") == string("jongle"));
            CHECK(find(text1, "junJle") == string("jongle"));

}

TEST_CASE("Test replacement of w and v or f and b") {
    string text1 = "xxx vmwer yyy";
            CHECK(find(text1, "Vmwer") == string("vmwer"));
            CHECK(find(text1, "vmWer") == string("vmwer"));
            CHECK(find(text1, "vmVer") == string("vmwer"));
            CHECK(find(text1, "Wmwer") == string("vmwer"));
            CHECK(find(text1, "wmwer") == string("vmwer"));
            CHECK(find(text1, "vmver") == string("vmwer"));
            CHECK(find(text1, "wmver") == string("vmwer"));
            CHECK(find(text1, "WmVer") == string("vmwer"));
            CHECK(find(text1, "WmWer") == string("vmwer"));
            CHECK(find(text1, "VmVer") == string("vmwer"));
    string text2 = "xxx yyy fiBo";
            CHECK(find(text2, "BiBo") == string("fiBo"));
            CHECK(find(text2, "fiBo") == string("fiBo"));
            CHECK(find(text2, "fibo") == string("fiBo"));
            CHECK(find(text2, "Bibo") == string("fiBo"));
            CHECK(find(text2, "FiFo") == string("fiBo"));
            CHECK(find(text2, "fiFo") == string("fiBo"));
            CHECK(find(text2, "FiBo") == string("fiBo"));
            CHECK(find(text2, "fibo") == string("fiBo"));
            CHECK(find(text2, "fIBO") == string("fiBo"));
            CHECK(find(text2, "FIBo") == string("fiBo"));
}
TEST_CASE("Test replacement of d and t") {
    string text1 = "deadpool yyy";
            CHECK(find(text1, "TeaDpool") == string("deadpool"));
            CHECK(find(text1, "teadpool") == string("deadpool"));
            CHECK(find(text1, "deatpool") == string("deadpool"));
            CHECK(find(text1, "teatpool") == string("deadpool"));
            CHECK(find(text1, "TeaTpool") == string("deadpool"));

}
TEST_CASE("exception test") {
    string text1 = "home yyy";
            
            CHECK_THROWS(find(text1, "me"));
            CHECK_THROWS(find(text1, "homerr"));
            CHECK_THROWS(find(text1, "om"));
            CHECK_THROWS(find(text1, "avt"));
            CHECK_THROWS(find(text1, ""));
    string text2 = "";
            CHECK_THROWS(find(text2, "ho"));
            CHECK_THROWS(find(text2, "homr"));
            CHECK_THROWS(find(text2, ""));

}

    TEST_CASE("Test for All kinds of") {
    string text1 = "xxx vacation";
            CHECK(find(text1, "wacadion") == string("vacation"));
            CHECK(find(text1, "vacatyun") == string("vacation"));
            CHECK(find(text1, "VACATION") == string("vacation"));
            CHECK(find(text1, "vacatyon") == string("vacation"));
            CHECK(find(text1, "wacadyuN") == string("vacation"));
            CHECK(find(text1, "vAcatYun") == string("vacation"));
            CHECK(find(text1, "vacatYUn") == string("vacation"));
            CHECK(find(text1, "WacaDyuN") == string("vacation"));
            CHECK(find(text1, "vAcatYun") == string("vacation"));
            CHECK(find(text1, "VaCaTiOn") == string("vacation"));
    string text = "avichaiAndTal";
            CHECK(find(text, "aVichayandTal") == string("avichaiAndTal"));
            CHECK(find(text, "avychaIAnddal") == string("avichaiAndTal"));
            CHECK(find(text, "aVicHAiANdTaL") == string("avichaiAndTal"));
            CHECK(find(text, "avichaiANDTal") == string("avichaiAndTal"));
            CHECK(find(text, "avYchaYAndTal") == string("avichaiAndTal"));
            CHECK(find(text, "avichaiAndtal") == string("avichaiAndTal"));
            CHECK(find(text, "aVichAiAndTal") == string("avichaiAndTal"));
            CHECK(find(text, "avichaiAnTDal") == string("avichaiAndTal"));
            CHECK(find(text, "avIchaiAndTAL") == string("avichaiAndTal"));
            CHECK(find(text, "avicHAYAnddAl") == string("avichaiAndTal"));
}



