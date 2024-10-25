#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// output text color
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void help(char program_name[]);
void court();
int get_wage(char c);
char *get_number(char court[], char old_number[]);

int main(int argc, char *argv[])
{
    if (argc == 2 && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)))
    {
        help(argv[0]);
    }
    else if (argc == 2 && ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--court") == 0)))
    {
        court();
    }
    else
    {
        if (argc == 3)
        {
            printf("%s", ANSI_COLOR_YELLOW);
            printf("Result: %s \t --> \t %s\n", argv[2], get_number(argv[1], argv[2]));
            printf("%s", ANSI_COLOR_RESET);
        }
        else if (argc > 3)
        {
            int i = 2;
            while (i < argc)
            {
                printf("%s", ANSI_COLOR_YELLOW);
                printf("Result: ");
                printf("%s", ANSI_COLOR_RESET);
                printf("%s", ANSI_COLOR_BLUE);
                printf("%s \t", argv[i]);
                printf("%s", ANSI_COLOR_RESET);
                printf("-->\t");
                printf("%s", ANSI_COLOR_GREEN);
                printf("%s\n", get_number(argv[1], argv[i]));
                printf("%s", ANSI_COLOR_RESET);
                i++;
            }
        }
        else
        {
            printf("For help run the program with -h or --help argument.\n");
        }
    }
}

// return a wage (value) of digit or letter
int get_wage(char c)
{
    int i = 0;
    char wages[] = "0123456789XABCDEFGHIJKLMNOPRSTUWYZ";
    int length = sizeof(wages) / sizeof(wages[0]);
    for (i = 0; i < length; ++i)
    {
        if (wages[i] == c)
        {
            break;
        }
    }
    return i;
}

// calculate a check digit and return full new register number
char *get_number(char court[], char old_number[])
{
    char *result;
    result = (char *)malloc(12 * sizeof(char));

    char full_number[11] = "\0";
    strcat(full_number, court);

    char filling[8];

    for (int i = 0; i < 8 - strlen(old_number); ++i)
    {
        filling[i] = '0';
        filling[i + 1] = '\0';
    }

    strcat(full_number, filling);
    strcat(full_number, old_number);

    int sum = 0;

    sum = sum + get_wage(full_number[0]) * 1;
    sum = sum + get_wage(full_number[1]) * 3;
    sum = sum + get_wage(full_number[2]) * 7;
    sum = sum + get_wage(full_number[3]) * 1;
    sum = sum + get_wage(full_number[4]) * 3;
    sum = sum + get_wage(full_number[5]) * 7;
    sum = sum + get_wage(full_number[6]) * 1;
    sum = sum + get_wage(full_number[7]) * 3;
    sum = sum + get_wage(full_number[8]) * 7;
    sum = sum + get_wage(full_number[9]) * 1;
    sum = sum + get_wage(full_number[10]) * 3;
    sum = sum + get_wage(full_number[11]) * 7;

    int number = sum % 10;

    char c_number[12];
    sprintf(c_number, "%d", number);

    strcat(result, court);
    strcat(result, "/");
    strcat(result, filling);
    strcat(result, old_number);
    strcat(result, "/");
    strcat(result, c_number);

    return result;
}

// print help
void help(char program_name[])
{
    printf("To execute the program use:\n");
    printf(ANSI_COLOR_GREEN);
    printf("%s <court_signature> <old_register_number>\n", program_name);
    printf(ANSI_COLOR_RESET);
    printf("You can compute a few of numbers writing out one after another, e.g.:\n");
    printf(ANSI_COLOR_GREEN);
    printf("%s <court_signature> <old_register_number> <old_register_number> <old_register_number>\n", program_name);
    printf(ANSI_COLOR_RESET);
    printf("To print all court signatures use:\n");
    printf(ANSI_COLOR_GREEN);
    printf("%s -c or --court\n", program_name);
    printf(ANSI_COLOR_RESET);
}

// print court sign
void court()
{
    char court_id[347][5] = {"WL1A", "SU1A", "OL1Y", "PT1B", "KA1B", "LU1B", "RA2G", "KO1B", "BI1B", "BB1B", "BI1P", "ZA1B", "OL1B", "TR1O", "JG1B",
                             "EL1B", "TO1B", "OP1B", "TR1B", "LD1B", "KS1B", "KI1B", "BY1B", "KA1Y", "SL1B", "LU1C", "TO1C", "PO1H", "SL1C", "KA1C", "SZ1C", "KR1C", "PL1C", "BB1C",
                             "PO2T", "KR1K", "CZ1C", "SL1Z", "KA1D", "TR1D", "RZ1D", "KR2Y", "KO1D", "EL1D", "SW1D", "EL1E", "OL1E", "SI1G", "GD1G", "GD1Y", "OL1G", "GL1G", "LE1G",
                             "OP1G", "PO1G", "SZ1O", "TO1G", "NS1G", "GW1G", "PL1G", "PO1Y", "LM1G", "WA1G", "PO1S", "RA1G", "TO1U", "SZ1G", "SZ1Y", "ZG2K", "BI2P", "ZA1H", "EL1I",
                             "BY1I", "ZA1J", "KZ1J", "PR1J", "KS1J", "GL1J", "LE1J", "KA1J", "JG1J", "KI1J", "KZ1A", "JG1K", "SZ1K", "GD1R", "KA1K", "KI1I", "OP1K", "KZ1E", "OL1K",
                             "KR2E", "KI1L", "OP1U", "CZ2C", "SW1K", "TB1K", "KO1L", "KN1K", "KN1N", "KI1K", "KO1K", "PO1K", "GD1E", "RA1K", "KR1P", "ZA1K", "LU1K", "KS1K", "ZG1K",
                             "KZ1R", "KR2K", "LD1K", "GD1I", "WA1L", "LE1L", "KS1E", "PO1L", "RZ1E", "SL1L", "OL1L", "NS1L", "WL1L", "RA1L", "PR1L", "JG1L", "LU1A", "LE1U", "CZ1L",
                             "LU1I", "JG1S", "RZ1A", "SR1L", "LD1Y", "SZ1L", "LM1L", "SI2S", "LD1O", "LD1M", "LU1U", "GD1M", "SL1M", "KR1M", "TB1M", "PO2A", "GW1M", "KA1M", "WR1M",
                             "SI1M", "PL1M", "BY1M", "EL2O", "OL1M", "NS2L", "NS1M", "KA1L", "CZ1M", "KR1Y", "SZ1M", "BY1N", "OL1N", "KR2I", "TB1N", "SW2K", "ZG1N", "EL1N", "GD2M",
                             "WA1N", "NS1S", "NS1T", "PO1N", "OP1N", "PO1O", "OL1C", "OP1L", "WR1E", "KR1O", "OL1O", "WR1O", "KI1T", "PT1O", "LU1O", "OP1O", "OS1O", "KI1O", "EL1O",
                             "OS1M", "KZ1W", "KZ1O", "KR1E", "WA1O", "LD1P", "SR2W", "WA1I", "PO1I", "KI1P", "RA2Z", "PT1P", "OL1P", "KZ1P", "PL1P", "PL1L", "SR2L", "SZ2S", "PO1P",
                             "PO2P", "KR1H", "OP1P", "WA1P", "OS1P", "PR1P", "PR1R", "RA1P", "KA1P", "GD2W", "LU1P", "OS1U", "SZ2T", "GL1R", "RA1R", "PT1R", "WL1R", "LU1R", "LD1R",
                             "PO1R", "RZ1R", "GL1S", "GL1Y", "LU1Y", "WL1Y", "RZ1Z", "KI1S", "KS1S", "SU1N", "BY2T", "SI1S", "KA1I", "BI3P", "PR2R", "SR1S", "PL1E", "KR2P", "KI1R",
                             "KR3I", "LD1H", "KO1E", "KR1S", "GW1S", "KN1S", "SL1S", "PL1O", "SI1P", "BI1S", "GD1S", "KA1S", "TB1S", "KI1H", "SZ1T", "GD1A", "KI1A", "GW1K", "OP1S",
                             "WR1T", "RZ1S", "KR1B", "ZG2S", "GW1U", "SU1S", "PO1A", "KO1I", "SZ1S", "OL1S", "GD2I", "BY1U", "RA1S", "PO1M", "WR1S", "PO1D", "SW1S", "KO2B", "ZG1S",
                             "BY1S", "SZ1W", "TB1T", "GL1T", "TR1T", "GD1T", "ZA1T", "PT1T", "TO1T", "PO1T", "WR1W", "BY1T", "TR2T", "KN1T", "KA1T", "RZ2Z", "KS2E", "KR1W", "SW1W",
                             "KO1W", "WA3M", "WA1M", "WA2M", "WA4M", "WA5M", "WA6M", "TO1W", "PO1B", "GD1W", "OL2G", "SI1W", "KR1I", "SR1W", "WL1W", "LU1W", "KI1W", "GL1W", "PO1E",
                             "WA1W", "WR1L", "WR1K", "PO1F", "ZG1W", "PO2H", "LM1W", "OS1W", "GL1Z", "NS1Z", "LM1Z", "ZA1Z", "CZ1Z", "SW1Z", "SR1Z", "LD1G", "JG1Z", "ZG1E", "LE1Z",
                             "PO1Z", "RA1Z", "ZG1G", "ZG1R", "BY1Z", "GL1X", "PL2M", "PL1Z", "BB1Z"};

    char court_name[347][30] = {"Aleksandrów Kujawski", "Augustów", "Bartoszyce", "Bełchatów", "Będzin", "Biała podlaska", "Białobrzegi", "Białogard",
                                "Białystok", "Bielsko-Biała", "Bielsk Podlaski", "Biłgoraj", "Biskupiec", "BochniaR1O", "Bolesławiec", "Braniewo", "Brodnica", "Brzeg", "Brzesko", "Brzeziny",
                                "Brzozów", "Busko Zdrój", "Bydgoszcz", "Bytom", "Bytów", "Chełm", "Chełmno", "Chodzież", "Chojnice", "Chorzów", "Choszczno", "Chrzanów", "Ciechanów", "Cieszyn",
                                "Czarnków", "Czernichów", "Częstochowa", "Człuchów", "Dąbrowa Górnicza", "Dąbrowa Tarnowska", "Dębica", "Dobczyce", "Drawsko Pomorskie", "Działdowo", "Dzierżoniów",
                                "Elbląg", "Ełk", "Garwolin", "Gdańsk", "Gdynia", "Giżycko", "Gliwice", "Głogów", "Głubczyce", "Gniezno", "Goleniów", "Golub-Dobrzyń", "Gorlice", "Gorzów Wielkopolski",
                                "Gostynin", "Gostyń", "Grajewo", "Grodzisk Mazowiecki", "Grodzisk Wlkp.", "Grójec", "Grudziądz", "Gryfice", "Gryfino", "Gubin", "Hajnówka", "Hrubieszów", "Iława",
                                "Inowrocław", "Janów Lubelski", "Jarocin", "Jarosław", "Jasło", "Jastrzębie-Zdrój", "Jawor", "Jaworzno", "Jelenia Góra", "Jędrzejów", "Kalisz", "Kamienna Góra",
                                "Kamień Pomorski", "Kartuzy", "Katowice", "Kazimierza wielka", "Kędzierzyn-koźle", "Kępno", "Kętrzyn", "Kęty", "Kielce", "Kluczbork", "Kłobuck", "Kłodzko", "Kolbuszowa",
                                "Kołobrzeg", "Koło", "Konin", "Końskie", "Koszalin", "Kościan", "Kościerzyna", "Kozienice", "Kraków", "Krasnystaw", "Kraśnik", "Krosno", "Krosno Odrzańskie", "Krotoszyn",
                                "Krzeszowice", "Kutno", "Kwidzyn", "Legionowo", "Legnica", "Lesko", "Leszno", "Leżajsk", "Lębork", "Lidzbark Warmiński", "Limanowa", "Lipno", "Lipsko", "Lubaczów", "Lubań",
                                "Lubartów", "Lubin", "Lubliniec", "Lublin", "Lwówek Śląski", "Łańcut", "Łask", "Łęczyca", "Łobez", "Łomża", "Łosice", "Łowicz", "Łódź", "Łuków", "Malbork", "Miastko",
                                "Miechów", "Mielec", "Międzychód", "Międzyrzecz", "Mikołów", "Milicz", "Mińsk Mazowiecki", "Mława", "Mogilno", "Morąg", "Mrągowo", "Mszana Dolna", "Muszyna", "Mysłowice",
                                "Myszków", "Myślenice", "Myślibórz", "Nakło nad Notecią", "Nidzica", "Niepołomice", "Nisko", "Nowa Ruda", "Nowa Sól", "Nowe Miasto Lubawskie", "Nowy Dwór Gdański",
                                "Nowy Dwór Mazowiecki", "Nowy Sącz", "Nowy Targ", "Nowy Tomyśl", "Nysa", "Oborniki", "Olecko", "Olesno", "Oleśnica", "Olkusz", "Olsztyn", "Oława", "Opatów", "Opoczno",
                                "Opole Lubelskie", "Opole", "Ostrołęka", "Ostrowiec Świętokrzyski", "Ostróda", "Ostrów Mazowiecka", "Ostrów Wielkopolski", "Ostrzeszów", "Oświęcim", "Otwock", "Pabianice",
                                "Pajęczno", "Piaseczno", "Piła", "Pińczów", "Pionki", "Piotrków Trybunalski", "Pisz", "Pleszew", "Płock", "Płońsk", "Poddębice", "Police", "Poznań (V)", "Poznań (VI)",
                                "Proszowice", "Prudnik", "Pruszków", "Przasnysz", "Przemyśl", "Przeworsk", "Przysucha", "Pszczyna", "Puck", "Puławy", "Pułtusk", "Pyrzyce", "Racibórz", "Radom", "Radomsko",
                                "Radziejów", "Radzyń Podlaski", "Rawa Mazowiecka", "Rawicz", "Ropczyce", "Ruda Śląska", "Rybnik", "Ryki", "Rypin", "Rzeszów", "Sandomierz", "Sanok", "Sejny", "Sępólno Krajeńskie",
                                "Siedlce", "Siemianowice Śląskie", "Siemiatycze", "Sieniawa", "Sieradz", "Sierpc", "Skała", "Skarżysko-Kamienna", "Skawina", "Skierniewice", "Sławno", "Słomniki", "Słubice",
                                "Słupca", "Słupsk", "Sochaczew", "Sokołów Podlaski", "Sokółka", "Sopot", "Sosnowiec", "Stalowa Wola", "Starachowice", "Stargard Szczeciński", "Starogard Gdański", "Staszów",
                                "Strzelce Krajeńskie", "Strzelce Opolskie", "Strzelin", "Strzyżów", "Sucha Beskidzka", "Sulechów", "Sulęcin", "Suwałki", "Szamotuły", "Szczecinek", "Szczecin", "Szczytno",
                                "Sztum", "Szubin", "Szydłowiec", "Śrem", "Środa Śląska", "Środa Wlkp.", "Świdnica", "Świdwin", "Świebodzin", "Świecie", "Świnoujście", "Tarnobrzeg", "Tarnowskie Góry",
                                "Tarnów", "Tczew", "Tomaszów Lubelski", "Tomaszów Mazowiecki", "Toruń", "Trzcianka", "Trzebnica", "Tuchola", "Tuchów", "Turek", "Tychy", "Tyczyn", "Ustrzyki Dolne",
                                "Wadowice", "Wałbrzych", "Wałcz", "Warszawa (IX)", "Warszawa (VI)", "Warszawa (VII)", "Warszawa (X)", "Warszawa (XIII)", "Warszawa (XV)", "Wąbrzeźno", "Wągrowiec", "Wejherowo",
                                "Węgorzewo", "Węgrów", "Wieliczka", "Wieluń", "Włocławek", "Włodawa", "Włoszczowa", "Wodzisław Śląski", "Wolsztyn", "Wołomin", "Wołów", "Wrocław", "Września", "Wschowa",
                                "Wyrzysk", "Wysokie Mazowieckie", "Wyszków", "Zabrze", "Zakopane", "Zambrów", "Zamość", "Zawiercie", "Ząbkowice Śląskie", "Zduńska Wola", "Zgierz", "Zgorzelec",
                                "Zielona Góra", "Złotoryja", "Złotów", "Zwoleń", "Żagań", "Żary", "Żnin", "Żory", "Żuromin", "Żyrardów", "Żywiec"};

    printf("Courts signatures list:\n");

    for (int i = 0; i < 347; i++)
    {
        printf(ANSI_COLOR_GREEN);
        printf("%s", court_id[i]);
        printf(ANSI_COLOR_RESET);
        printf(" - ");
        printf(ANSI_COLOR_YELLOW);
        printf("%s", court_name[i]);
        printf(ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE);
        printf(" | ");
        printf(ANSI_COLOR_RESET);

        if (i == 346)
        {
            printf("\n");
        }
    }
}