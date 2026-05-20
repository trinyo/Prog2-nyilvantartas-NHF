#include "gtest_lite.h"
#include "Szemely.h"
#include "Hallgato.h"
#include "Oktato.h"
#include "Parser.h"
#include "memtrace.h"

#ifdef CPORTA
int main() {
    GTINIT(std::cin);
    std::cout << "=== Tesztek futtatasa ===" << std::endl << std::endl;

    TEST(Hallgato, KonstruktorAlap)
        Hallgato h("Mernoki", 1, 3);
        EXPECT_EQ(0, h.getNzh());
    END

    TEST(Hallgato, KonstruktorTeljes)
        Hallgato h("Test Elek", "TE0001", "test@uni.hu", "Mernoki", 2, 5);
        EXPECT_STREQ("TE0001", h.getKod().c_str());
    END

    TEST(Hallgato, AddZH)
        Hallgato h("Mernoki", 1, 3);
        h.addZH(85.0);
    END

    TEST(Hallgato, AddMultipleZH)
        Hallgato h("Mernoki", 1, 5);
        h.addZH(85.0);
        h.addZH(90.0);
    END

    TEST(Hallgato, GetOsztondijAlapertelmezett)
        Hallgato h("Mernoki", 1, 3);
        EXPECT_EQ(false, h.getOsztondij());
    END

    TEST(Hallgato, SetOsztondijIgen)
        Hallgato h("Mernoki", 1, 3);
        h.setOsztondij(true);
        EXPECT_EQ(true, h.getOsztondij());
    END

    TEST(Hallgato, SetOsztondijNem)
        Hallgato h("Mernoki", 1, 3);
        h.setOsztondij(false);
        EXPECT_EQ(false, h.getOsztondij());
    END

    TEST(Hallgato, GetStatuszAlapertelmezett)
        Hallgato h("Mernoki", 1, 3);
        EXPECT_STREQ("aktiv", h.getStatusz().c_str());
    END

    TEST(Hallgato, AddCsoport)
        Hallgato h("Mernoki", 1, 3);
        h.addCsoport("G01");
        EXPECT_EQ(1, h.getCsoportSzam());
    END

    TEST(Hallgato, AddMultipleCsoport)
        Hallgato h("Mernoki", 1, 3);
        h.addCsoport("G01");
        h.addCsoport("G02");
        EXPECT_EQ(2, h.getCsoportSzam());
    END

    TEST(Hallgato, GetCsoport)
        Hallgato h("Mernoki", 1, 3);
        h.addCsoport("G01");
        h.addCsoport("G02");
        EXPECT_STREQ("G01", h.getCsoport(0).c_str());
    END

    TEST(Oktato, KonstruktorAlap)
        Oktato o("PhD", "IIT", "I-123", "Algo", "", 5);
        EXPECT_STREQ("IIT", o.getTanszek().c_str());
    END

    TEST(Oktato, KonstruktorTeljes)
        Oktato o("Dr. Kovacs", "KJ0001", "kovacs@uni.hu", "PhD", "IIT", "I-101", "Prog1", "", 5);
        EXPECT_STREQ("KJ0001", o.getKod().c_str());
    END

    TEST(Oktato, GetTanszek)
        Oktato o("MSc", "TMIT", "II-201", "Web", "cs 14", 3);
        EXPECT_STREQ("TMIT", o.getTanszek().c_str());
    END

    TEST(Oktato, AddCsoport)
        Oktato o("PhD", "IIT", "I-123", "Algo", "", 5);
        o.addCsoport("G01");
        EXPECT_EQ(1, o.getCsoportSzam());
    END

    TEST(Parser, UresKonstruktor)
        Parser p;
        EXPECT_EQ(0, p.getMeret());
    END

    TEST(Parser, HozzaadHallgato)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        EXPECT_EQ(1, p.getMeret());
    END

    TEST(Parser, HozzaadOktato)
        Parser p;
        Oktato* o = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(o);
        EXPECT_EQ(1, p.getMeret());
    END

    TEST(Parser, HozzaadTobb)
        Parser p;
        Hallgato* h1 = new Hallgato("Teszt Egy", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        Hallgato* h2 = new Hallgato("Teszt Kettő", "TE0002", "test@uni.hu", "Mernokinf", 2, 5);
        Oktato* o1 = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(h1);
        p.hozzaad(h2);
        p.hozzaad(o1);
        EXPECT_EQ(3, p.getMeret());
    END

    TEST(Parser, KeresKodAlapjanMegtalal)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        Szemely* talalt = p.keresKodAlapjan("TE0001");
        EXPECT_TRUE(talalt != 0);
    END

    TEST(Parser, KeresKodAlapjanNemTalal)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        Szemely* talalt = p.keresKodAlapjan("XXXXXXXX");
        EXPECT_TRUE(talalt == 0);
    END

    TEST(Parser, TorolHallgato)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        EXPECT_EQ(1, p.getMeret());
        bool sikerult = p.torol("TE0001");
        EXPECT_TRUE(sikerult);
        EXPECT_EQ(0, p.getMeret());
    END

    TEST(Parser, TorolOktato)
        Parser p;
        Oktato* o = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(o);
        EXPECT_EQ(1, p.getMeret());
        bool sikerult = p.torol("TT0001");
        EXPECT_TRUE(sikerult);
        EXPECT_EQ(0, p.getMeret());
    END

    TEST(Parser, TorolNemLetezik)
        Parser p;
        bool sikerult = p.torol("XXXXXXXX");
        EXPECT_EQ(false, sikerult);
    END

    TEST(Parser, TorolKettoUtanEgyMarad)
        Parser p;
        Hallgato* h1 = new Hallgato("Teszt Egy", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        Hallgato* h2 = new Hallgato("Teszt Kettő", "TE0002", "test@uni.hu", "Mernokinf", 2, 5);
        p.hozzaad(h1);
        p.hozzaad(h2);
        p.torol("TE0001");
        EXPECT_EQ(1, p.getMeret());
        Szemely* megmaradt = p.keresKodAlapjan("TE0002");
        EXPECT_TRUE(megmaradt != 0);
    END

    TEST(Parser, ListazMindenkit)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        p.listazMindenkit();
    END

    TEST(Parser, ListazHallgatok)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        p.listazHallgatok();
    END

    TEST(Parser, ListazOktatok)
        Parser p;
        Oktato* o = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(o);
        p.listazOktatok();
    END

    TEST(Parser, ListazCsoportAlapjan)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        h->addCsoport("G01");
        p.hozzaad(h);
        p.listazCsoportAlapjan("G01");
    END

    TEST(Parser, ListazCsoportAlapjanNemTalal)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        h->addCsoport("G01");
        p.hozzaad(h);
        p.listazCsoportAlapjan("G99");
    END

    TEST(Parser, ListazTanszekAlapjan)
        Parser p;
        Oktato* o = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(o);
        p.listazTanszekAlapjan("IIT");
    END

    TEST(Parser, ListazTanszekAlapjanNemTalal)
        Parser p;
        Oktato* o = new Oktato("Dr. Teszt", "TT0001", "test@uni.hu", "PhD", "IIT", "I-100", "Algo", "", 3);
        p.hozzaad(o);
        p.listazTanszekAlapjan("XXXX");
    END

    TEST(Parser, ListazOsztondijasok)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        h->setOsztondij(true);
        p.hozzaad(h);
        p.listazOsztondijasok();
    END

    TEST(Parser, ListazKivaloStatuszuak)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        p.listazKivaloStatuszuak();
    END

    TEST(Parser, ListazPZH_Kotelezettek)
        Parser p;
        Hallgato* h = new Hallgato("Teszt Elek", "TE0001", "test@uni.hu", "Mernokinf", 1, 5);
        p.hozzaad(h);
        p.listazPZH_Kotelezettek();
    END

    TEST(Parser, BeolvasCsv)
        Parser p;
        p.beolvas("test_data.csv");
        EXPECT_EQ(41, p.getMeret());
    END

    TEST(Parser, BeolvasCsvOktatoEsHallgato)
        Parser p;
        p.beolvas("test_data.csv");
        p.listazOktatok();
        p.listazHallgatok();
    END

    std::cout << "\n=== Tesztek vege ===" << std::endl;
    GTEND(std::cout)
    return 0;
}
#endif