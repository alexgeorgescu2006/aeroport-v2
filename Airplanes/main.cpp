#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <windows.h>
#include <string>
#include <cctype>

using namespace std;

fstream empli ( "EMPLOYEE" , ios::in | ios::out ) ;
fstream plai ( "PLANE" , ios::in | ios::out ) ;
fstream logi ( "LOGIN" , ios::in | ios::out ) ;
fstream passi ( "PASSWORDS" , ios::in | ios::out ) ;
ifstream citi ( "CITY" ) ;
ifstream countri ( "COUNTRY" ) ;
ifstream namesi ( "NAMES" ) ;
ifstream langui ( "LANGUAGES" ) ;
ifstream salari ( "SALARIES" ) ;
ifstream ptypi ( "PTYPE" ) ;
ifstream pwighti ( "PWEIGHT" ) ;
ifstream plngi ( "PLENGTH" ) ;
ifstream pwdthi ( "PWIDTH" ) ;
ifstream phghi ( "PHEIGHT" ) ;
ifstream debugi ( "DEBUGI" ) ;

fstream ofs ;


char name  [ 10001 ] [ 25 ] , city [ 200 ] [ 20 ] , country [ 200 ] [ 20 ] , jobtypes [ 25 ] [ 25 ] , languages [ 25 ] [ 25 ] , planetypes [ 16 ] [ 25 ];
int salaries [ 25 ] , planeseats [ 16 ] , planeweight [ 16 ] , planelength [ 16 ] , planewidth [ 16 ] , planeheight [ 16 ] ;
int gr ;

void ARRAY_READ ( ) {
    int i = 0 ;

}

struct {
    char NAME [ 20 ] ;
    char PASS [ 20 ] ;
} PASSWORDS [ 200 ] ;

struct DDATE {
    int DDAY ;
    int MMONTH ;
    int YYEAR ;
} ;

struct SSIZE {
    int LENGTH , WIDTH , HEIGHT ;
} ;

struct LOCATIONS {
    char CITY [ 25 ] ;
    char COUNTRY [ 25 ] ;
} ;

struct {
    char IDL [ 10 ] ;
    char IDG [ 15 ] ;
    char FIRST_NAME [ 40 ] ;
    char LAST_NAME [ 20 ] ;
    DDATE DDATE_OF_BIRTH;
    LOCATIONS LOCATION ;
} CUSTOMER [ 300000 ] ;

struct EMPLOYEE {
    char IDL [ 10 ] ;
    char IDG [ 14 ] ;
    char FIRST_NAME [ 40 ] ;
    char LAST_NAME [ 20 ] ;
    DDATE DDATE_OF_BIRTH;
    char TYPE_OF_JOB [ 15 ] ;
    int NUMBER_OF_LANGUAGES_SPOKEN ;
    char LANGUAGES_SPOKEN [ 10 ] [ 15 ] ;
    int SALARY_MMONTHLY ;
    char BANK_ACC [ 25 ] ;
    DDATE DDATE_OF_START ;
    int VACATION_DDAYS ;
    LOCATIONS LOCATION ;
} EMPLOYEE [ 300000 ] ;

struct PLANE {
    char IDL [ 10 ] ;
    char IDG [ 7 ] ;
    char TYPE_OF_PLANE [ 30 ] ;
    int MAX_SEATS ;
    int MAX_WEIGHT ;
    SSIZE SSIZES ;
    DDATE LAST_ITP;
    LOCATIONS LOCATION ;
} PLANE [ 300000 ] ;

void CUSTOMER_READ ( int &n ) {
    fstream custi ( "CUSTOMER" , ios::in | ios::out ) ;
    int i = 0 ;
    custi >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        custi >> CUSTOMER [ i ] .IDL ;
        custi >> CUSTOMER [ i ] .IDG ;
        custi >> CUSTOMER [ i ] .FIRST_NAME ;
        custi >> CUSTOMER [ i ] .LAST_NAME ;
        custi >> CUSTOMER [ i ] .DDATE_OF_BIRTH.DDAY ;
        custi >> CUSTOMER [ i ] .DDATE_OF_BIRTH.MMONTH ;
        custi >> CUSTOMER [ i ] .DDATE_OF_BIRTH.YYEAR ;
        custi >> CUSTOMER [ i ] .LOCATION.CITY ;
        custi >> CUSTOMER [ i ] .LOCATION.COUNTRY ;
        system( "cls" ) ;
    }
    custi.close ( ) ;
}

void EMPLOYEE_READ ( int &n ) {
    int i = 0 ;
    empli >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        empli >> EMPLOYEE [ i ] .IDL ;
        empli >> EMPLOYEE [ i ] .IDG ;
        empli >> EMPLOYEE [ i ] .FIRST_NAME ;
        empli >> EMPLOYEE [ i ] .LAST_NAME ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_BIRTH.DDAY ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_BIRTH.MMONTH ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_BIRTH.YYEAR ;
        empli >> EMPLOYEE [ i ] .TYPE_OF_JOB ;
        empli >> EMPLOYEE [ i ] .NUMBER_OF_LANGUAGES_SPOKEN ;
        for ( int j ; j < EMPLOYEE [ i ] .NUMBER_OF_LANGUAGES_SPOKEN ; j ++ )
            empli >> EMPLOYEE [ i ] .LANGUAGES_SPOKEN [ j ] ;
        empli >> EMPLOYEE [ i ] .SALARY_MMONTHLY ;
        empli >> EMPLOYEE [ i ] .BANK_ACC ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_START.DDAY ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_START.MMONTH ;
        empli >> EMPLOYEE [ i ] .DDATE_OF_START.YYEAR ;
        empli >> EMPLOYEE [ i ] .VACATION_DDAYS ;
        empli >> EMPLOYEE [ i ] .LOCATION.CITY ;
        empli >> EMPLOYEE [ i ] .LOCATION.COUNTRY ;
    }
}

void PLANE_READ ( int &n ) {
    int i = 0 ;
    plai >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        plai >> PLANE [ i ] .IDL ;
        plai >> PLANE [ i ] .IDG ;
        plai >> PLANE [ i ] .TYPE_OF_PLANE ;
        plai >> PLANE [ i ] .MAX_SEATS ;
        plai >> PLANE [ i ] .MAX_WEIGHT ;
        plai >> PLANE [ i ] .SSIZES.HEIGHT ;
        plai >> PLANE [ i ] .SSIZES.LENGTH ;
        plai >> PLANE [ i ] .SSIZES.WIDTH ;
        plai >> PLANE [ i ] .LAST_ITP.DDAY ;
        plai >> PLANE [ i ] .LAST_ITP.MMONTH ;
        plai >> PLANE [ i ] .LAST_ITP.YYEAR ;
    }
}

void data_read ( int &n , int &m , int &p ) {
    CUSTOMER_READ ( n ) ;
    //EMPLOYEE_READ ( m ) ;
    //PLANE_READ ( p ) ;
}

void CUSTOMER_RAND ( ) {
    ofs.open("CUSTOMER", ios::out | ios::trunc);
    int i = 0 , j = 0 , n , c ;
    for ( i = 0 ; i < 300000 ; i ++ ) {
        ofs<< i << " " ;
        c = ( rand ( ) % 42 ) + 48 ;
        for ( j = 0 ; j < 14 ; j ++ ) {
            while ( c > 57 && c < 65 ) {
                c = rand ( ) % 42 + 48 ;
            }
            ofs<< ( char ) c  ;
            c = rand ( ) % 42 + 48 ;
        }
        ofs<< " " ;
        j = rand ( ) % 10000 ;
        ofs<< name [ j ] << " " ;
        j = rand ( ) % 10000 ;
        ofs<< name [ j ] << " " ;
        j = rand ( ) % 31 ;
        if ( j > 29 ) {
            ofs<< j << " " ;
            int m = rand ( ) % 12 ;
            if ( j == 29 && m == 2 ) {
                ofs << m << " " ;
                m = ( rand ( ) % 13 + 488 ) * 4 ;
                ofs<< m << " " ;
            }
            else{
                if ( j == 29 && m != 2 ){
                    ofs << j << " " ;
                    j = rand ( ) % 62 + 1954 ;
                    ofs << j << " " ;
                }
                else
                {
                    if ( j = 30 ) {
                        while ( m == 2 ) {
                            m = rand ( ) % 12 ;
                        }
                        ofs<< m << " " ;
                        j = rand ( ) % 62 + 1954 ;
                        ofs<< j << " " ;
                    }
                    else
                    {
                        while ( m != 2 && m != 4 && m != 6 && m != 9 && m != 11 )
                        {
                            m = rand ( ) % 12 ;
                        }
                        ofs<< m << " " ;
                        j = rand ( ) % 62 + 1954 ;
                        ofs<< j << " " ;
                    }
                }
            }
        }
        else {
            ofs<< j << " " ;
            j = rand ( ) % 12 ;
            ofs<< j << " " ;
            j = rand ( ) % 62 + 1954 ;
            ofs<< j << " " ;
        }
        j = rand ( ) % 10000 ;
        ofs<< city [ j ] << " " << country [ j ]  << "\n" ;
    }
}

void EMPLOYEE_RAND ( ) {
    ofs.open("EMPLOYEE", ios::out | ios::trunc);
    int i = 0 , j = 0 , n , c ;
    for ( i = 0 ; i < 300000 ; i ++ ) {
        ofs << i << " " ;
        c = ( rand ( ) % 42 ) + 48 ;
        for ( j = 0 ; j < 14 ; j ++ ) {
            while ( c > 57 && c < 65 ) {
                c = rand ( ) % 42 + 48 ;
            }
            ofs << ( char ) c  ;
            c = rand ( ) % 42 + 48 ;
        }
        ofs << " " ;
        j = rand ( ) % 10000 ;
        ofs << name [ j ] << " " ;
        j = rand ( ) % 10000 ;
        ofs << name [ j ] << " " ;
        j = rand ( ) % 31 ;
        if ( j > 29 ) {
            ofs << j << " " ;
            int m = rand ( ) % 12 ;
            if ( j == 29 && m == 2 ) {
                ofs  << m << " " ;
                m = ( rand ( ) % 13 + 485 ) * 4 ;
                ofs << m << " " ;
            }
            else{
                if ( j == 29 && m != 2 ){
                    ofs << j << " " ;
                    j = rand ( ) % 62 + 1947 ;
                    ofs << j << " " ;
                }
                else
                {
                    if ( j = 30 ) {
                        while ( m == 2 ) {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                        j = rand ( ) % 62 + 1947 ;
                        ofs << j << " " ;
                    }
                    else
                    {
                        while ( m != 2 && m != 4 && m != 6 && m != 9 && m != 11 )
                        {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                        j = rand ( ) % 62 + 1947 ;
                        ofs << j << " " ;
                    }
                }
            }
        }
        else {
            ofs << j << " " ;
            j = rand ( ) % 12 ;
            ofs << j << " " ;
            j = rand ( ) % 62 + 1947 ;
            ofs << j << " " ;
        }
        int l ;
        l = rand ( ) % 25 ;
        ofs << jobtypes [ l ] << " " ;
        j = rand ( ) % 5 ;
        ofs << j << " " ;
        int h [ 25 ] = {0} , x ;
        for ( int m = 0 ; m < j ; m ++ )
        {
            x = rand ( ) % 30 ;
            while ( h [ x ] != 0 ){
                x = rand ( ) % 30 ;
            }
            ofs << languages [ x ] << " " ;
            h [ x ] ++ ;
        }
        ofs << salaries [ l ] << " " ;
        c = ( rand ( ) % 42 ) + 48 ;
        for ( j = 0 ; j < 24 ; j ++ ) {
            while ( c > 57 && c < 65 ) {
                c = rand ( ) % 42 + 48 ;
            }
            ofs << ( char ) c  ;
            c = rand ( ) % 42 + 48 ;
        }
        ofs << " " ;
        j = rand ( ) % 31 ;
        if ( j > 29 ) {
            ofs << j << " " ;
            int m = rand ( ) % 12 ;
            if ( j == 29 && m == 2 ) {
                ofs  << m << " " ;
                m = ( rand ( ) % 13 + 498 ) * 4 ;
                ofs << m << " " ;
            }
            else{
                if ( j == 29 && m != 2 ){
                    ofs << j << " " ;
                    j = rand ( ) % 62 + 1980 ;
                    ofs << j << " " ;
                }
                else
                {
                    if ( j = 30 ) {
                        while ( m == 2 ) {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                        j = rand ( ) % 62 + 1980 ;
                        ofs << j << " " ;
                    }
                    else
                    {
                        while ( m != 2 && m != 4 && m != 6 && m != 9 && m != 11 )
                        {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                        j = rand ( ) % 62 + 1980 ;
                        ofs << j << " " ;
                    }
                }
            }
        }
        else {
            ofs << j << " " ;
            j = rand ( ) % 12 ;
            ofs << j << " " ;
            j = rand ( ) % 62 + 1980 ;
            ofs << j << " " ;
        }
        j = rand ( ) % 20 ;
        ofs << j << " " ;
        j = rand ( ) % 10000 ;
        ofs << city [ j ] << " " << country [ j ]  << "\n" ;
    }
}

void PLANE_RAND ( ) {
    ofs.open("CUSTOMER", ios::out | ios::trunc);
    int i = 0 , j = 0 , n , c ;
    for ( i = 0 ; i < 300000 ; i ++ ) {
        ofs << i << " N" ;
        c = ( rand ( ) % 42 ) + 48 ;
        for ( j = 0 ; j < 5 ; j ++ ) {
            while ( c > 57 && c < 65 ) {
                c = rand ( ) % 42 + 48 ;
            }
            ofs << ( char ) c  ;
            c = rand ( ) % 42 + 48 ;
        }
        ofs << " " ;
        j = rand ( ) % 6 ;
        ofs << planetypes [ j ] << " " ;
        ofs << planeseats [ j ] << " " ;
        ofs << planeweight [ j ] << " " ;
        j = rand ( ) % 31 ;
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int YYEAR = aTime->tm_year + 1900;
        if ( j > 29 ) {
            ofs << j << " " ;
            int m = rand ( ) % 12 ;
            if ( j == 29 && m == 2 && ( YYEAR - 1 ) % 4 == 0) {
                ofs  << m << " " ;
            }
            else{
                if ( j == 29 && m != 2 ){
                    ofs << j << " " ;
                }
                else
                {
                    if ( j = 30 ) {
                        while ( m == 2 ) {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                    }
                    else
                    {
                        while ( m != 2 && m != 4 && m != 6 && m != 9 && m != 11 )
                        {
                            m = rand ( ) % 12 ;
                        }
                        ofs << m << " " ;
                    }
                }
            }
        }
        else {
            ofs << j << " " ;
            j = rand ( ) % 12 ;
            ofs << j << " " ;
        }
        ofs << YYEAR - 1 << " " ;
        j = rand ( ) % 10000 ;
        ofs << city [ j ] << " " << country [ j ]  << "\n" ;
    }
}

void data_rand ( ) {
    ARRAY_READ ( ) ;
    CUSTOMER_RAND ( ) ;
    EMPLOYEE_RAND ( ) ;
    PLANE_RAND ( ) ;
}

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void passwordread ( char PASS [ 20 ] [ 20 ] , char NAMES [ 20 ] [ 20 ] , int &n ) {
    int i = 0 ;
    passi >> n ;
    for ( i = 0 ; i < n; i ++ ) {
        int j = 0 ;
        char ch ;
        do
        {
            passi >> ch ;
            PASS [ i ] [ j ] = ch ;
            j ++ ;
        } while ( ch != '|' ) ;
        PASS [ i ] [ j - 1 ] = NULL ;
        j = 0 ;
        do
        {
            logi >> ch ;
            NAMES [ i ] [ j ] = ch ;
            j ++ ;
        } while ( ch != '|' ) ;
        NAMES [ i ] [ j - 1 ] = NULL ;
    }
}

int main()
{
    int ok = 1 , okp = 1 , okfirstscreen = 1 , custommaxx , employeemaxx , planesmaxx ;
    char op;
    int rand ;
    int i = 0 , n = 0  , passmaxx ;
    char NAMES [ 20 ] = {} , NAMES_ [ 20 ] [ 20 ] = {} ;
    char PASS [ 20 ] = {} , PASS_ [ 20 ] [ 20 ] = {} ;
    passwordread ( PASS_ , NAMES_ , passmaxx ) ;
    /*cin >> rand ;
    if ( rand == 1 )
        data_rand ( ) ;
    else*/
    data_read ( custommaxx , employeemaxx , planesmaxx ) ;
    system ( "cls" ) ;
    cout << " ---------------------------------------\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |               WELCOME!              |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |    To travel, use enter for next    |\n" ;
    cout << " |   page or the number indicated on   |\n" ;
    cout << " |              the page .             |\n" ;
    cout << " |       To go back, press escape.     |\n" ;
    cout << " |          To exit, use space.        |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " ---------------------------------------\n" ;
    getch ( ) ;
    while ( ok >= 1 ) {
        system ( "cls" ) ;
        cout << " ---------------------------------------\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |       REGISTER         LOGIN        |\n" ;
        cout << " |         (1)             (2)         |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " |                                     |\n" ;
        cout << " ---------------------------------------\n" ;
        op = getch ( ) ;
        switch ( op ) {
            case ' ' :{
                if ( op == ' ' ) {
                    system ("cls") ;
                    cout << " ---------------------------------------\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |          HAVE A GOOD DAY!           |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " ---------------------------------------\n" ;
                    cout << op << " " ;
                    getch();
                    abort();
                }
                break ;
            }
            case '2' :{
                for ( int aaaa = 0 ; aaaa < 20 ; aaaa ++ ) {
                    NAMES [ aaaa ] = PASS [ aaaa ] = NULL ;
                }
                ok = 1 ;
                while ( ok == 1 )
                {
                    system ( "cls" ) ;
                    cout << " ---------------------------------------\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |               LOG IN                |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |   NAME     : ________________       |\n" ;
                    cout << " |   PASSWORD : ________________       |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " ---------------------------------------\n" ;
                    i = n = 0 ;
                    okp = 1 ;
                    while ( okp == 1 && ok != 2 ) {
                        gotoxy ( 16 + i , 8 ) ;
                        op = getch ( ) ;
                        system ( "cls" );
                        switch ( op ) {
                            case 27 : {
                                ok = 2 ;
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |       REGISTER         LOGIN        |\n" ;
                                cout << " |         (1)             (2)         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                break ;
                            }
                            case ' ' : {
                                int h = 0 ;
                                system ( "cls" ) ;
                                gotoxy ( 0 , 0 ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |               LOG IN                |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |   NAME     : " ;
                                for ( int j = 0 ; j < 16 ; j ++ )
                                {
                                    if ( j < i )
                                        {
                                            cout << NAMES [ h ] ;
                                            h++ ;
                                        }
                                    else
                                        cout << "_" ;
                                }
                                cout << "       |\n" ;
                                cout << " |   PASSWORD : ________________       |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                break ;
                            }
                            case '\b' :
                            {
                                    int h = 0 ;
                                    if ( i > 0 ) i -- ;
                                    gotoxy ( 16 + i , 9 ) ;
                                    system ( "cls" );
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |               LOG IN                |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                       if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                            }
                            case 13 :
                            {
                                if ( i > 0 ) {
                                    okp = 0 ;
                                }
                                else
                                {
                                    int h = 0 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |               LOG IN                |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                }
                            }
                            default : {
                                if ( op != 13 ) {
                                    int h = 0 ;
                                    gotoxy ( 16 + i , 9 ) ;
                                    NAMES [ i ] = op ;
                                    i ++ ;
                                    system ( "cls" );
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |               LOG IN                |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                       if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                }
                            }
                        }
                    }
                    if ( ok != 2 ) {
                        int h = 0 ;
                        system ( "cls" );
                        cout << " ---------------------------------------\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |               LOG IN                |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |   NAME     : " ;
                        for ( int j = 0 ; j < 16 ; j ++ )
                        {
                           if ( j < i )
                                {
                                    cout << NAMES [ h ] ;
                                    h++ ;
                                }
                            else
                                cout << "_" ;
                        }
                        cout << "       |\n" ;
                        cout << " |   PASSWORD : ________________       |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " ---------------------------------------\n" ;
                        while ( okp == 0) {
                            gotoxy ( 16 + n , 9  ) ;
                            op = getch ( ) ;
                            system ( "cls" );
                            switch ( op ) {
                                case 27 : {
                                    ok = 2 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |       REGISTER         LOGIN        |\n" ;
                                    cout << " |         (1)             (2)         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                                }
                                case ' ' : {
                                    int h = 0 ;
                                    system ( "cls" ) ;
                                    gotoxy ( 0 , 0 ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |               LOG IN                |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    h = 0 ;
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : " ;
                                     for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < n )
                                            {
                                                cout << PASS [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |          CAN'T INSERT SPACE         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                                }
                                case '\b' : {
                                        int h = 0 ;
                                        if ( n > 0 ) n -- ;
                                        gotoxy ( 16 + n , 9 ) ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |               LOG IN                |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        h = 0 ;
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                         for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                        break ;
                                }
                                case 13 : {
                                    if ( n > 0 ) {
                                        okp = 2 ;
                                    }
                                    else
                                    {
                                        int h = 0 ;
                                        system ( "cls" ) ;
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |               LOG IN                |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        h = 0 ;
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                         for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |    PASSWORD NEEDS TO BE AT LEAST    |\n" ;
                                        cout << " |          ONE CHARACTER LONG         |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                    }
                                }
                                default : {
                                    if ( op != 13 ) {
                                        int h = 0 ;
                                        PASS [ n ] = op ;
                                        n ++ ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |               LOG IN                |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                        h = 0 ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                    }
                                }
                            }
                        }
                        int search1 , search2 ;
                        int maxx , ok2 ;
                        if ( i > n ) {
                            maxx = i ;
                        }
                        else
                            maxx = n ;
                        for ( search1 = 0 ; search1 < passmaxx ; search1 ++ ) {
                            ok2 = 1 ;
                            search2 = 0 ;
                            while ( search2 < maxx ) {
                                if ( search2 < i && NAMES_ [ search1 ] [ search2 ] != NAMES [ search2 ] ) {
                                   // cout << NAMES_ [ search1 ] [ search2 ] << " " << NAMES [ search2 ] << "\n" ;
                                    search2 = maxx ;
                                    ok2 = 0 ;
                                }

                                if ( search2 < n && PASS_ [ search1 ] [ search2 ] != PASS [ search2 ] )
                                {
                                    //cout << PASS_ [ search1 ] [ search2 ] << " " << PASS [ search2 ] << "\n" ;
                                    search2 = maxx ;
                                    ok2 = 0 ;
                                }
                                search2 ++ ;
                            }
                            if ( ok2 == 1 ) {
                                ok = 0 ;
                                search1 = passmaxx ;
                            }
                        }
                        if ( ok == 1 ) {
                            system ( "cls" ) ;
                            cout << " ---------------------------------------\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |               LOG IN                |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |   NAME     : ________________       |\n" ;
                            cout << " |   PASSWORD : ________________       |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |      PASSWORD OR NAME INCORRECT     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " ---------------------------------------\n" ;
                            getch();
                        }
                    }
                }
                break;
                ok = 'p';
            }
            case '1' :{
                i = n = 0 ;
                for ( int aaaa = 0 ; aaaa < 20 ; aaaa ++ ) {
                    NAMES [ aaaa ] = PASS [ aaaa ] = NULL ;
                }
                ok = 1 ;
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |              REGISTER               |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |   NAME     : ________________       |\n" ;
                cout << " |   PASSWORD : ________________       |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                i = n = 0 ;
                okp = 1 ;
                while ( okp == 1 && ok != 2 ) {
                    gotoxy ( 16 + i , 8 ) ;
                    op = getch ( ) ;
                    system ( "cls" );
                    switch ( op ) {
                        case 27 : {
                            ok = 2 ;
                            system ( "cls" ) ;
                            cout << " ---------------------------------------\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |       REGISTER         LOGIN        |\n" ;
                            cout << " |         (1)             (2)         |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " ---------------------------------------\n" ;
                            break ;
                        }
                        if ( ok != 2 ) {
                                case ' ' : {
                                int h = 0 ;
                                system ( "cls" ) ;
                                gotoxy ( 0 , 0 ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |              REGISTER               |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |   NAME     : " ;
                                for ( int j = 0 ; j < 16 ; j ++ )
                                {
                                    if ( j < i )
                                        {
                                            cout << NAMES [ h ] ;
                                            h++ ;
                                        }
                                    else
                                        cout << "_" ;
                                }
                                cout << "       |\n" ;
                                cout << " |   PASSWORD : ________________       |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                break ;
                            }
                            case '\b' :
                            {
                                    int h = 0 ;
                                    if ( i > 0 ) i -- ;
                                    gotoxy ( 16 + i , 9 ) ;
                                    system ( "cls" );
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              REGISTER               |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                       if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                            }
                            case 13 :
                            {
                                if ( i > 0 ) {
                                    okp = 0 ;
                                }
                                else
                                {
                                    int h = 0 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              REGISTER               |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                }
                            }
                            default : {
                                if ( op != 13 ) {
                                    int h = 0 ;
                                    gotoxy ( 16 + i , 9 ) ;
                                    NAMES [ i ] = op ;
                                    i ++ ;
                                    system ( "cls" );
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              REGISTER               |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                       if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                }
                            }
                        }
                    }
                    if ( ok != 2 ) {
                        int h = 0 ;
                        system ( "cls" );
                        cout << " ---------------------------------------\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |              REGISTER               |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |   NAME     : " ;
                        for ( int j = 0 ; j < 16 ; j ++ )
                        {
                           if ( j < i )
                                {
                                    cout << NAMES [ h ] ;
                                    h++ ;
                                }
                            else
                                cout << "_" ;
                        }
                        cout << "       |\n" ;
                        cout << " |   PASSWORD : ________________       |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " |                                     |\n" ;
                        cout << " ---------------------------------------\n" ;
                        while ( okp == 0 && ok != 2 )
                        {
                            gotoxy ( 16 + n , 9  ) ;
                            op = getch ( ) ;
                            system ( "cls" );
                            switch ( op ) {
                                case 27 : {
                                    ok = 2 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |       REGISTER         LOGIN        |\n" ;
                                    cout << " |         (1)             (2)         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                                }
                                case ' ' : {
                                    int h = 0 ;
                                    system ( "cls" ) ;
                                    gotoxy ( 0 , 0 ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              REGISTER               |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |   NAME     : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < i )
                                            {
                                                cout << NAMES [ h ] ;
                                                h++ ;
                                            }
                                        else
                                            cout << "_" ;
                                    }
                                    h = 0 ;
                                    cout << "       |\n" ;
                                    cout << " |   PASSWORD : " ;
                                    for ( int j = 0 ; j < 16 ; j ++ )
                                    {
                                        if ( j < n - 1 )
                                            {
                                                cout << "*" ;
                                                h++ ;
                                            }
                                        else
                                        {
                                            if ( j == n - 1 )
                                            {
                                                cout << PASS [ h ] ;
                                                h++ ;
                                            }
                                             else
                                                    cout << "_" ;
                                        }
                                    }
                                    cout << "       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |          CAN'T INSERT SPACE         |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    break ;
                                }
                                case '\b' :
                                {
                                        int h = 0 ;
                                        if ( n > 0 ) n -- ;
                                        gotoxy ( 16 + n , 9 ) ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |              REGISTER               |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        h = 0 ;
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n - 1 )
                                                {
                                                    cout << "*" ;
                                                    h++ ;
                                                }
                                            else
                                            {
                                                if ( j == n - 1 )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                                 else
                                                    cout << "_" ;
                                            }
                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                        break ;
                                }
                                case 13 : {
                                    if ( n > 0 ) {
                                        okp = 2 ;
                                    }
                                    else
                                    {
                                        int h = 0 ;
                                        system ( "cls" ) ;
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |              REGISTER               |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        h = 0 ;
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n - 1 )
                                                {
                                                    cout << "*" ;
                                                    h++ ;
                                                }
                                            else
                                            {
                                                if ( j == n - 1 )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                                 else
                                                    cout << "_" ;
                                            }
                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |    PASSWORD NEEDS TO BE AT LEAST    |\n" ;
                                        cout << " |          ONE CHARACTER LONG         |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                    }
                                }
                                default : {
                                    if ( op != 13 ) {
                                        int h = 0 ;
                                        PASS [ n ] = op ;
                                        n ++ ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |              REGISTER               |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < i )
                                                {
                                                    cout << NAMES [ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |   PASSWORD : " ;
                                        h = 0 ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                            if ( j < n - 1 )
                                                {
                                                    cout << "*" ;
                                                    h++ ;
                                                }
                                            else
                                            {
                                                if ( j == n - 1 )
                                                {
                                                    cout << PASS [ h ] ;
                                                    h++ ;
                                                }
                                                else
                                                    cout << "_" ;
                                            }

                                        }
                                        cout << "       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                    }
                                }
                            }
                        }
                    }

                }
                if ( ok != 2 ) {
                    passi.seekg(0, ios::beg);
                    passi << passmaxx + 1 << "\n";
                    for ( int j = 0 ; j < passmaxx ; j ++ ) {
                        int pp = 0 ;
                        while ( PASS_ [ j ] [ pp ] != NULL ) {
                            passi << PASS_ [ j ] [ pp ] ;
                            pp ++ ;
                        }
                        passi << "|\n" ;
                    }
                    for ( int j = 0 ; j < n ; j ++ ) {
                        PASS_ [ passmaxx ] [ j ] = PASS [ j ] ;
                        passi << PASS_ [ passmaxx ] [ j ] ;
                    }
                    passi << "|" << "\n" ;
                    logi.seekg(0, ios::beg);
                    for ( int j = 0 ; j < passmaxx ; j ++ ) {
                        int pp = 0 ;
                        while ( NAMES_ [ j ] [ pp ] != NULL ) {
                            logi << NAMES_ [ j ] [ pp ] ;
                            pp ++ ;
                        }
                        logi << "|\n" ;
                    }
                    for ( int j = 0 ; j < i ; j ++ ) {
                        NAMES_ [ passmaxx ] [ j ] = NAMES [ j ] ;
                        logi << NAMES_ [ passmaxx ] [ j ] ;
                    }
                    logi << "|\n" ;
                    passi.seekg(0, ios::beg);
                    logi.seekg(0, ios::beg);
                    passwordread ( PASS_ , NAMES_ , passmaxx ) ;
                    cout << " ---------------------------------------\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |              REGISTER               |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |       REGISTERED SUCCESFULLY        |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " ---------------------------------------\n" ;
                    getch ( ) ;
                }
                ok = 'p';
                break ;
            }
            default : {

                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |       REGISTER         LOGIN        |\n" ;
                cout << " |         (1)             (2)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |          PRESS (1) OR (2)           |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                getch ( );
                break ;
            }
            }
    }

    char IDL [ 10 ] ;
    char IDG [ 14 ] ;
    char FNAME [ 40 ] ;
    char LNAME [ 20 ] ;
    char DATE [ 9 ] ;
    char CIT [ 25 ] , COUNT [ 25 ] ;
    char CUSTOMERNAME [ 20 ] , CUSTOMERIDG [ 20 ] ;
    system ( "cls" ) ;
    cout << " ---------------------------------------\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
    cout << " |        (1)               (2)        |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
    cout << " |        (3)              (4)         |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " ---------------------------------------\n" ;
    while ( okp == 2 ) {
    op = getch ( ) ;
        switch ( op ) {
            case '1' : {
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                char opp = 0 ;
                do {
                    opp = getch ( ) ;
                    switch ( opp ) {
                        case '1' : {
                            for ( int aaaa = 0 ; aaaa < 20 ; aaaa ++ ) {
                                NAMES [ aaaa ] = PASS [ aaaa ] = NULL ;
                            }
                            ok = 1 ;
                            while ( ok == 1 )
                            {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |           CUSTOMER  SEARCH          |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |   NAME     : ________________       |\n" ;
                                cout << " |   IDG      : ________________       |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                i = n = 0 ;
                                okp = 1 ;
                                while ( okp == 1 && ok != 2 ) {
                                    gotoxy ( 16 + i , 8 ) ;
                                    op = getch ( ) ;
                                    system ( "cls" );
                                    switch ( op ) {
                                        case 27 : {
                                            ok = 2 ;
                                            system ( "cls" ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                            cout << " |        (1)               (2)        |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                            cout << " |        (3)              (4)         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            break ;
                                        }
                                        case ' ' : {
                                            int h = 0 ;
                                            system ( "cls" ) ;
                                            gotoxy ( 0 , 0 ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |           CUSTOMER  SEARCH          |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |   NAME     : " ;
                                            for ( int j = 0 ; j < 16 ; j ++ )
                                            {
                                                if ( j < i )
                                                    {
                                                       // cout << j << " " << i << " " ;
                                                        cout << CUSTOMERNAME [ h ] ;
                                                        h++ ;
                                                    }
                                                else
                                                    cout << "_" ;
                                            }
                                            cout << "       |\n" ;
                                            cout << " |   IDG      : ________________       |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |          CAN'T INSERT SPACE         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            break ;
                                        }
                                        case '\b' :
                                        {
                                                int h = 0 ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 16 + i , 9 ) ;
                                                system ( "cls" );
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                   if ( j < i )
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                        }
                                        case 13 :
                                        {
                                            if ( i > 0 ) {
                                                okp = 0 ;
                                            }
                                            else
                                            {
                                                int h = 0 ;
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                    if ( j >= i )
                                                        cout << "_" ;
                                                    else
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }

                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                cout << " |          ONE CHARACTER LONG         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                getch ( ) ;
                                                break;
                                            }
                                        }
                                        default : {
                                            if ( op != 13 && op != ' ' ) {
                                                int h = 0 ;
                                                gotoxy ( 16 + i , 9 ) ;
                                                CUSTOMERNAME[ i ] = op ;
                                                i ++ ;
                                                system ( "cls" );
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                   if ( j < i )
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                            }
                                        }
                                    }
                                }
                                    if ( ok != 2 ) {
                                        int h = 0 ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |           CUSTOMER  SEARCH          |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                           if ( j < i )
                                                {
                                                    cout << CUSTOMERNAME[ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |   IDG      : ________________       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                        while ( okp == 0 && ok != 2 )
                                        {
                                            gotoxy ( 16 + n , 9  ) ;
                                            op = getch ( ) ;
                                            system ( "cls" );
                                            switch ( op ) {
                                                case 27 : {
                                                    ok = 2 ;
                                                    system ( "cls" ) ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                    cout << " |        (1)               (2)        |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                    cout << " |        (3)              (4)         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                    break ;
                                                }
                                                case ' ' : {
                                                    int h = 0 ;
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |   NAME     : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ )
                                                    {
                                                        if ( j < i )
                                                            {
                                                                cout << CUSTOMERNAME[ h ] ;
                                                                h++ ;
                                                            }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    h = 0 ;
                                                    cout << "       |\n" ;
                                                    cout << " |   IDG      : " ;
                                                     for ( int j = 0 ; j < 16 ; j ++ )
                                                    {
                                                        if ( j < n )
                                                            {
                                                                cout << CUSTOMERIDG [ h ] ;
                                                                h++ ;
                                                            }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                    break ;
                                                }
                                                case '\b' :
                                                {
                                                        int h = 0 ;
                                                        if ( n > 0 ) n -- ;
                                                        gotoxy ( 16 + n , 9 ) ;
                                                        system ( "cls" );
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        h = 0 ;
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                         for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                        break ;
                                                }
                                                case 13 : {
                                                    if ( n > 0 ) {
                                                        okp = 2 ;
                                                    }
                                                    else
                                                    {
                                                        int h = 0 ;
                                                        system ( "cls" ) ;
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                       cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        h = 0 ;
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                         for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |    PASSWORD NEEDS TO BE AT LEAST    |\n" ;
                                                        cout << " |          ONE CHARACTER LONG         |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                    }
                                                }
                                                default : {
                                                    if ( op != 13 ) {
                                                        int h = 0 ;
                                                        CUSTOMERIDG [ n ] = op ;
                                                        n ++ ;
                                                        system ( "cls" );
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |           CUSTOMER  SEARCH          |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                        h = 0 ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                    }
                                                }
                                            }
                                        }
                                        int search1 , search2 ;
                                        int maxx , ok2 ;
                                        if ( i > n ) {
                                            maxx = i ;
                                        }
                                        else
                                            maxx = n ;
                                        for ( search1 = 0 ; search1 < custommaxx ; search1 ++ ) {
                                            ok2 = 1 ;
                                            search2 = 0 ;
                                            while ( search2 < maxx ) {
                                                if ( search2 < i && CUSTOMER[ search1 ] .LAST_NAME[ search2 ]  != CUSTOMERNAME[ search2 ] ) {
                                                    search2 = maxx ;
                                                    ok2 = 0 ;
                                                }
                                                if ( search2 < n && CUSTOMER[ search1 ] .IDG [ search2 ] != CUSTOMERIDG [ search2 ] )
                                                {
                                                    search2 = maxx ;
                                                    ok2 = 0 ;
                                                }
                                                search2 ++ ;
                                            }
                                            if ( ok2 == 1 ) {
                                                ok = 0 ;
                                                cout << "    ID LOCAL        :  " << CUSTOMER [ search1 ] .IDL << "\n" ;
                                                cout << "    ID GLOBAL       :  " << CUSTOMER [ search1 ] .IDG << "\n\n" ;
                                                cout << "    FIRST NAME      :  " << CUSTOMER [ search1 ] .FIRST_NAME << "\n" ;
                                                cout << "    LAST NAME       :  " << CUSTOMER [ search1 ] .LAST_NAME << "\n\n" ;
                                                cout << "    DATE OF BIRTH   :  " << CUSTOMER [ search1 ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ search1 ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ search1 ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                cout << "    CURRENT CITY    :  " << CUSTOMER [ search1 ] .LOCATION.CITY << "\n" ;
                                                cout << "    CURRENT COUNTRY :  " << CUSTOMER [ search1 ] .LOCATION.COUNTRY << "\n" ;
                                                search1 = custommaxx ;
                                            }
                                        }
                                        if ( ok == 1 ) {
                                            system ( "cls" ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |           CUSTOMER  SEARCH          |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |        COULDN'T FIND CUSTOMER       |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            getch ( ) ;
                                        }
                                    }
                            }
                            break;
                            ok = 'p';
                        }
                        case '3' : {
                            for ( int aaaa = 0 ; aaaa < 20 ; aaaa ++ ) {
                                NAMES [ aaaa ] = PASS [ aaaa ] = NULL ;
                            }
                            ok = 1 ;
                            while ( ok == 1 )
                            {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |   NAME     : ________________       |\n" ;
                                cout << " |   IDG      : ________________       |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                i = n = 0 ;
                                okp = 1 ;
                                while ( okp == 1 && ok != 2 ) {
                                    gotoxy ( 16 + i , 8 ) ;
                                    op = getch ( ) ;
                                    system ( "cls" );
                                    switch ( op ) {
                                        case 27 : {
                                            ok = 2 ;
                                            system ( "cls" ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                            cout << " |        (1)               (2)        |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                            cout << " |        (3)              (4)         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            break ;
                                        }
                                        case ' ' : {
                                            int h = 0 ;
                                            system ( "cls" ) ;
                                            gotoxy ( 0 , 0 ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |   NAME     : " ;
                                            for ( int j = 0 ; j < 16 ; j ++ )
                                            {
                                                if ( j < i )
                                                    {
                                                       // cout << j << " " << i << " " ;
                                                        cout << CUSTOMERNAME [ h ] ;
                                                        h++ ;
                                                    }
                                                else
                                                    cout << "_" ;
                                            }
                                            cout << "       |\n" ;
                                            cout << " |   IDG      : ________________       |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |          CAN'T INSERT SPACE         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            break ;
                                        }
                                        case '\b' :
                                        {
                                                int h = 0 ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 16 + i , 9 ) ;
                                                system ( "cls" );
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                   if ( j < i )
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                        }
                                        case 13 :
                                        {
                                            if ( i > 0 ) {
                                                okp = 0 ;
                                            }
                                            else
                                            {
                                                int h = 0 ;
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                    if ( j >= i )
                                                        cout << "_" ;
                                                    else
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }

                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                cout << " |          ONE CHARACTER LONG         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                getch ( ) ;
                                                break;
                                            }
                                        }
                                        default : {
                                            if ( op != 13 && op != ' ' ) {
                                                int h = 0 ;
                                                gotoxy ( 16 + i , 9 ) ;
                                                CUSTOMERNAME[ i ] = op ;
                                                i ++ ;
                                                system ( "cls" );
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |   NAME     : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ )
                                                {
                                                   if ( j < i )
                                                        {
                                                            cout << CUSTOMERNAME[ h ] ;
                                                            h++ ;
                                                        }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |   IDG      : ________________       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                            }
                                        }
                                    }
                                }
                                    if ( ok != 2 ) {
                                        int h = 0 ;
                                        system ( "cls" );
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |   NAME     : " ;
                                        for ( int j = 0 ; j < 16 ; j ++ )
                                        {
                                           if ( j < i )
                                                {
                                                    cout << CUSTOMERNAME[ h ] ;
                                                    h++ ;
                                                }
                                            else
                                                cout << "_" ;
                                        }
                                        cout << "       |\n" ;
                                        cout << " |   IDG      : ________________       |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                        while ( okp == 0)
                                        {
                                            gotoxy ( 16 + n , 9  ) ;
                                            op = getch ( ) ;
                                            system ( "cls" );
                                            switch ( op ) {
                                                case 27 : {
                                                    ok = 2 ;
                                                    system ( "cls" ) ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                    cout << " |        (1)               (2)        |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                    cout << " |        (3)              (4)         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                    break ;
                                                }
                                                case ' ' : {
                                                    int h = 0 ;
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |   NAME     : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ )
                                                    {
                                                        if ( j < i )
                                                            {
                                                                cout << CUSTOMERNAME[ h ] ;
                                                                h++ ;
                                                            }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    h = 0 ;
                                                    cout << "       |\n" ;
                                                    cout << " |   IDG      : " ;
                                                     for ( int j = 0 ; j < 16 ; j ++ )
                                                    {
                                                        if ( j < n )
                                                            {
                                                                cout << CUSTOMERIDG [ h ] ;
                                                                h++ ;
                                                            }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                    break ;
                                                }
                                                case '\b' :
                                                {
                                                        int h = 0 ;
                                                        if ( n > 0 ) n -- ;
                                                        gotoxy ( 16 + n , 9 ) ;
                                                        system ( "cls" );
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        h = 0 ;
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                         for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                        break ;
                                                }
                                                case 13 : {
                                                    if ( n > 0 ) {
                                                        okp = 2 ;
                                                    }
                                                    else
                                                    {
                                                        int h = 0 ;
                                                        system ( "cls" ) ;
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        h = 0 ;
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                         for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |    PASSWORD NEEDS TO BE AT LEAST    |\n" ;
                                                        cout << " |          ONE CHARACTER LONG         |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                    }
                                                }
                                                default : {
                                                    if ( op != 13 ) {
                                                        int h = 0 ;
                                                        CUSTOMERIDG [ n ] = op ;
                                                        n ++ ;
                                                        system ( "cls" );
                                                        cout << " ---------------------------------------\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |   NAME     : " ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < i )
                                                                {
                                                                    cout << CUSTOMERNAME[ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |   IDG      : " ;
                                                        h = 0 ;
                                                        for ( int j = 0 ; j < 16 ; j ++ )
                                                        {
                                                            if ( j < n )
                                                                {
                                                                    cout << CUSTOMERIDG [ h ] ;
                                                                    h++ ;
                                                                }
                                                            else
                                                                cout << "_" ;
                                                        }
                                                        cout << "       |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " |                                     |\n" ;
                                                        cout << " ---------------------------------------\n" ;
                                                    }
                                                }
                                            }
                                        }
                                        int search1 , search2 ;
                                        int maxx , ok2 ;
                                        if ( i > n ) {
                                            maxx = i ;
                                        }
                                        else
                                            maxx = n ;
                                        for ( search1 = 0 ; search1 < custommaxx ; search1 ++ ) {
                                            ok2 = 1 ;
                                            search2 = 0 ;
                                            while ( search2 < maxx ) {
                                                if ( search2 < i && CUSTOMER[ search1 ] .LAST_NAME[ search2 ]  != CUSTOMERNAME[ search2 ] ) {
                                                    search2 = maxx ;
                                                    ok2 = 0 ;
                                                }
                                                if ( search2 < n && CUSTOMER[ search1 ] .IDG [ search2 ] != CUSTOMERIDG [ search2 ] )
                                                {
                                                    search2 = maxx ;
                                                    ok2 = 0 ;
                                                }
                                                search2 ++ ;
                                            }
                                            if ( ok2 == 1 ) {
                                                ofs.open("CUSTOMER", ios::out | ios::trunc);
                                                ofs << custommaxx - 1 << "\n" ;
                                                for ( int j = 0 ; j < search1 ; j ++ ) {
                                                    ofs << CUSTOMER [ j ] .IDL << " " ;
                                                    ofs << CUSTOMER [ j ] .IDG << " " ;
                                                    ofs << CUSTOMER [ j ] .FIRST_NAME << " " ;
                                                    ofs << CUSTOMER [ j ] .LAST_NAME << " " ;
                                                    ofs << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << " " ;
                                                    ofs << CUSTOMER [ j ] .LOCATION.CITY << " " ;
                                                    ofs <<  CUSTOMER [ j ] .LOCATION.COUNTRY << "\n" ;

                                                }
                                                for ( int j = search1 + 1  ; j < custommaxx ; j ++ ) {
                                                    ofs << CUSTOMER [ j ] .IDL << " " ;
                                                    ofs << CUSTOMER [ j ] .IDG << " " ;
                                                    ofs << CUSTOMER [ j ] .FIRST_NAME << " " ;
                                                    ofs << CUSTOMER [ j ] .LAST_NAME << " " ;
                                                    ofs << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << " " ;
                                                    ofs << CUSTOMER [ j ] .LOCATION.CITY << " " ;
                                                    ofs <<  CUSTOMER [ j ] .LOCATION.COUNTRY << "\n" ;
                                                }
                                                custommaxx -- ;
                                                ofs.close () ;
                                                CUSTOMER_READ ( custommaxx ) ;
                                                search1 = custommaxx ;
                                                ok = 1 ;
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |           CUSTOMER  REMOVED         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                getch ( ) ;
                                            }
                                        }
                                        if ( ok == 1 ) {
                                            system ( "cls" ) ;
                                            cout << " ---------------------------------------\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |           CUSTOMER  REMOVAL         |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |        COULDN'T FIND CUSTOMER       |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " |                                     |\n" ;
                                            cout << " ---------------------------------------\n" ;
                                            getch ( ) ;
                                        }
                                    }
                            }
                            okp = 2 ;
                            break;
                            ok = 'p';
                        }
                        case '2' : {
                                int okex = 0 ;
                                for ( i = 0 ; i < 25 ; i ++ ) {
                                    IDL [ i ] = IDG [ i ] = FNAME [ i ] = LNAME [ i ] = DATE [ i ] = CIT [ i ] = COUNT [ i ] = NULL ;
                                }
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |              ADD CUSTOMER           |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " | FIRST NAME : ________________       |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                                i = 0 ;
                                ok = 1 ;
                                if ( okex == 0 ) {
                                    while ( ok ) {
                                        gotoxy ( 16 + i , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | FIRST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << FNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | FIRST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << FNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i > 0 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " | FIRST NAME : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ ) {
                                                        if ( j < i ) {
                                                            cout << FNAME  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                system ( "cls" ) ;
                                                FNAME [ i ] = opp ;
                                                i ++ ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | FIRST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << FNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    ok = 1 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |  LAST NAME : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    i = 0 ;
                                    while ( ok ) {
                                        gotoxy ( 16 + i , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  LAST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << LNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  LAST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << LNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i > 0 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  LAST NAME : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ ) {
                                                        if ( j < i ) {
                                                            cout << LNAME  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                system ( "cls" ) ;
                                                LNAME [ i ] = opp ;
                                                i ++ ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  LAST NAME : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << LNAME  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    ok = 1 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |  ID NUMBER : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    i = 0 ;
                                    while ( ok ) {
                                        gotoxy ( 16 + i , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  ID NUMBER : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << IDG  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  ID NUMBER : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << IDG  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i > 0 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  ID NUMBER : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ ) {
                                                        if ( j < i ) {
                                                            cout << IDG  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                system ( "cls" ) ;
                                                IDG [ i ] = opp ;
                                                i ++ ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  ID NUMBER : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << IDG  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    ok = 1 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |  BIRTHDATE : __/__/____             |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    i = 0 ;
                                    int l = 0 ;
                                    while ( ok ) {
                                        gotoxy ( 16 + i + l , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  BIRTHDATE : " ;
                                                for ( int j = 0 ; j < 8 ; j ++ ) {
                                                    if ( j == 2 || j == 4 ) {
                                                        cout << "/" ;
                                                    }
                                                    if ( j < i ) {
                                                        cout << DATE [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "             |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                if ( i <= 4 )
                                                    l = 1 ;
                                                if ( i <= 2 )
                                                    l = 0 ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  BIRTHDATE : " ;
                                                for ( int j = 0 ; j < 8 ; j ++ ) {
                                                    if ( j == 2 || j == 4 ) {
                                                        cout << "/" ;
                                                    }
                                                    if ( j < i ) {
                                                        cout << DATE [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "             |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i == 8 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  BIRTHDATE : " ;
                                                    for ( int j = 0 ; j < 8 ; j ++ ) {
                                                        if ( j == 2 || j == 4 ) {
                                                            cout << "/" ;
                                                        }
                                                        if ( j < i ) {
                                                            cout << DATE  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "             |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |       DATE NEEDS TO BE EIGHT        |\n" ;
                                                    cout << " |             DIGITS LONG             |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                if ( i < 8 ) {
                                                    if ( isdigit ( opp ) ) {
                                                            system ( "cls" ) ;
                                                            DATE [ i ] = opp ;
                                                            i ++ ;
                                                            if ( i > 2 )
                                                                l = 1 ;
                                                            if ( i > 4 )
                                                                l = 2 ;
                                                            gotoxy ( 0 , 0 ) ;
                                                            int h = 0 ;
                                                            cout << " ---------------------------------------\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |              ADD CUSTOMER           |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |  BIRTHDATE : " ;
                                                            for ( int j = 0 ; j < 8 ; j ++ ) {
                                                                if ( j == 2 || j == 4 ) {
                                                                    cout << "/" ;
                                                                }
                                                                if ( j < i ) {
                                                                    cout << DATE [ h ] ;
                                                                    h ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "             |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " ---------------------------------------\n" ;
                                                    }
                                                    else
                                                    {
                                                            system ( "cls" ) ;
                                                            gotoxy ( 0 , 0 ) ;
                                                            int h = 0 ;
                                                            cout << " ---------------------------------------\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |              ADD CUSTOMER           |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |  BIRTHDATE : " ;
                                                            for ( int j = 0 ; j < 8 ; j ++ ) {
                                                                if ( j == 2 || j == 4 ) {
                                                                    cout << "/" ;
                                                                }
                                                                if ( j < i ) {
                                                                    cout << DATE [ h ] ;
                                                                    h ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "             |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |         CAN ONLY INSERT DIGITS      |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " |                                     |\n" ;
                                                            cout << " ---------------------------------------\n" ;
                                                    }
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  BIRTHDATE : " ;
                                                    for ( int j = 0 ; j < 8 ; j ++ ) {
                                                        if ( j == 2 || j == 4 ) {
                                                            cout << "/" ;
                                                        }
                                                        if ( j < i ) {
                                                            cout << DATE  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "             |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |       DATE NEEDS TO BE EIGHT        |\n" ;
                                                    cout << " |             DIGITS LONG             |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    ok = 1 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |     CITY   : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    i = 0 ;
                                    while ( ok ) {
                                        gotoxy ( 16 + i , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |     CITY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << CIT  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |     CITY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << CIT  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i > 0 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |     CITY   : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ ) {
                                                        if ( j < i ) {
                                                            cout << CIT  [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                system ( "cls" ) ;
                                                CIT [ i ] = opp ;
                                                i ++ ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |     CITY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << CIT  [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    ok = 1 ;
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |  COUNTRY   : ________________       |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    i = 0 ;
                                    while ( ok ) {
                                        gotoxy ( 16 + i , 8 ) ;
                                        opp = getch ( ) ;
                                        system ( "cls" ) ;
                                        switch ( opp ) {
                                            case 27 : {
                                                system ( "cls" ) ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                                cout << " |        (1)               (2)        |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                                cout << " |        (3)              (4)         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                okex = 1 ;
                                                ok = 0 ;
                                                break ;
                                            }
                                            case ' ' : {
                                                system ( "cls" ) ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  COUNTRY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << COUNT [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |          CAN'T INSERT SPACE         |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case '\b' : {
                                                system ( "cls" ) ;
                                                if ( i > 0 ) i -- ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  COUNTRY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << COUNT [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                            case 13 : {
                                                if ( i > 0 ) {
                                                    ok = 0 ;
                                                }
                                                else
                                                {
                                                    system ( "cls" ) ;
                                                    gotoxy ( 0 , 0 ) ;
                                                    int h = 0 ;
                                                    cout << " ---------------------------------------\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |              ADD CUSTOMER           |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |  COUNTRY   : " ;
                                                    for ( int j = 0 ; j < 16 ; j ++ ) {
                                                        if ( j < i ) {
                                                            cout << COUNT [ h ] ;
                                                            h ++ ;
                                                        }
                                                        else
                                                            cout << "_" ;
                                                    }
                                                    cout << "       |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " |      NAME NEEDS TO BE AT LEAST      |\n" ;
                                                    cout << " |          ONE CHARACTER LONG         |\n" ;
                                                    cout << " |                                     |\n" ;
                                                    cout << " ---------------------------------------\n" ;
                                                }
                                                break ;
                                            }
                                            default : {
                                                system ( "cls" ) ;
                                                COUNT[ i ] = opp ;
                                                i ++ ;
                                                gotoxy ( 0 , 0 ) ;
                                                int h = 0 ;
                                                cout << " ---------------------------------------\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |              ADD CUSTOMER           |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |  COUNTRY   : " ;
                                                for ( int j = 0 ; j < 16 ; j ++ ) {
                                                    if ( j < i ) {
                                                        cout << COUNT [ h ] ;
                                                        h ++ ;
                                                    }
                                                    else
                                                        cout << "_" ;
                                                }
                                                cout << "       |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " |                                     |\n" ;
                                                cout << " ---------------------------------------\n" ;
                                                break ;
                                            }
                                        }
                                    }
                                }
                                if ( okex == 0 ) {
                                    CUSTOMER_READ ( custommaxx ) ;
                                    ofs.open("CUSTOMER", ios::out | ios::trunc);
                                    ofs << custommaxx + 1 << "\n" ;
                                    for ( int j = 0 ; j < custommaxx ; j ++ ) {
                                        ofs << CUSTOMER [ j ] .IDL << " " ;
                                        ofs << CUSTOMER [ j ] .IDG << " " ;
                                        ofs << CUSTOMER [ j ] .FIRST_NAME << " " ;
                                        ofs << CUSTOMER [ j ] .LAST_NAME << " " ;
                                        ofs << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << " " << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << " " ;
                                        ofs << CUSTOMER [ j ] .LOCATION.CITY << " " ;
                                        ofs <<  CUSTOMER [ j ] .LOCATION.COUNTRY << "\n" ;

                                    }
                                    custommaxx ++ ;
                                    ofs << custommaxx << " " ;
                                    ofs << IDG << " " ;
                                    ofs << FNAME << " " << LNAME << " " ;
                                    ofs << DATE [ 0 ] << DATE [ 1 ] << " " << DATE [ 2 ] << DATE [ 3 ] << " " << DATE [ 4 ] << DATE [ 5 ] << DATE [ 6 ] << DATE [ 7 ] << " " ;
                                    ofs << CIT << " " << COUNT << "\n" ;
                                    ofs.close ( ) ;
                                    CUSTOMER_READ ( custommaxx );
                                    system ( "cls" ) ;
                                    cout << " ---------------------------------------\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |              ADD CUSTOMER           |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |             CUSTOMER ADDED          |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " |                                     |\n" ;
                                    cout << " ---------------------------------------\n" ;
                                    getch ( ) ;
                                }
                                okp = 2 ;
                                opp = '2' ;
                                break ;
                        }
                        case '4' : {
                            CUSTOMER_READ ( custommaxx );
                            char oppp ;
                            int j = 0 ;
                            int okex = 1 ;
                            system( "cls" ) ;
                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                            cout << "            " << j + 1 << "/" << custommaxx ;
                            while ( okex ) {
                                oppp = getch ( ) ;
                                switch ( oppp ) {
                                    case 'a' : {
                                        system( "cls" ) ;
                                        if ( j > 0 ) j -- ;
                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                        cout << "            " << j + 1 << "/" << custommaxx ;
                                        break ;
                                    }
                                    case 'd' : {
                                        system( "cls" ) ;
                                        if ( j < custommaxx - 1 ) j ++ ;
                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                        cout << "            " << j + 1 << "/" << custommaxx ;
                                        break ;
                                    }
                                    case 's' : {
                                        system( "cls" ) ;
                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                        cout << "           _____/" << custommaxx ;
                                        char charac [ 6 ] = { NULL } , lol ;
                                        int okpppp = 1 , pos = 0 ;
                                        while ( okpppp ) {
                                            gotoxy ( 11 + pos , 13 ) ;
                                            lol = getch ( ) ;
                                            switch ( lol )
                                            {
                                                case 's' : {
                                                    okpppp = 0 ;
                                                    system( "cls" ) ;
                                                    cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                    cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                    cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                    cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                    cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                    cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                    cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                                    cout << "            " << j + 1 << "/" << custommaxx ;
                                                    break ;
                                                }
                                                case 27 : {
                                                    okpppp = 0 ;
                                                    system( "cls" ) ;
                                                    cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                    cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                    cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                    cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                    cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                    cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                    cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                                    cout << "            " << j + 1 << "/" << custommaxx ;
                                                    break ;
                                                }
                                                case '\b' : {
                                                    if ( pos > 0 ) {
                                                            pos -- ;
                                                            int popo = 0 ;
                                                            system( "cls" ) ;
                                                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n           " ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "/" << custommaxx ;
                                                        }
                                                        else {
                                                            system( "cls" ) ;
                                                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n" ;
                                                            cout << "    NUMBER TOO BIG \n\n           " ;
                                                            int popo = 0 ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "/" << custommaxx ;
                                                        }
                                                    break ;
                                                }
                                                case 13 : {
                                                    int numb = 0 , opo = 0 ;
                                                    while ( opo < pos ) {
                                                        numb = numb * 10 + ( charac [ opo ] - '0' ) ;
                                                        opo ++ ;
                                                    }
                                                    if ( numb > custommaxx ) {
                                                            system ( "cls" ) ;
                                                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n" ;
                                                            cout << "    NUMBER TOO BIG \n\n           " ;
                                                            int popo = 0 ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "/" << custommaxx ;
                                                    }
                                                    else
                                                    {
                                                        j = numb - 1 ;
                                                        okpppp = 0 ;
                                                        system( "cls" ) ;
                                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n" ;
                                                        cout << "            " << j + 1 << "/" << custommaxx ;
                                                    }
                                                    break ;
                                                }
                                                default : {
                                                    if ( isdigit ( lol ) ) {
                                                        if ( pos < 5 ) {
                                                            charac [ pos ] = lol ;
                                                            pos ++ ;
                                                            int popo = 0 ;
                                                            system( "cls" ) ;
                                                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n\n\n           " ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "/" << custommaxx ;
                                                        }
                                                        else {
                                                            system( "cls" ) ;
                                                            cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                            cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                            cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                            cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                            cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                            cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                            cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n" ;
                                                            cout << "    NUMBER TOO BIG \n\n           " ;
                                                            int popo = 0 ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                            cout << "/" << custommaxx ;
                                                        }
                                                    }
                                                    else {
                                                        system( "cls" ) ;
                                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n" ;
                                                        cout << "    WRITE A NUMBER TO SEARCH \n\n           " ;
                                                        int popo = 0 ;
                                                            for ( int opo = 0 ; opo < 5 ; opo ++ ) {
                                                                if ( opo < pos ) {
                                                                    cout << charac [ popo ] ;
                                                                    popo ++ ;
                                                                }
                                                                else
                                                                    cout << "_" ;
                                                            }
                                                        cout << "/" << custommaxx ;
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                        break ;
                                    }
                                    case 27 : {
                                        system ( "cls" ) ;
                                        cout << " ---------------------------------------\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                        cout << " |        (1)               (2)        |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                        cout << " |        (3)              (4)         |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " |                                     |\n" ;
                                        cout << " ---------------------------------------\n" ;
                                        okex = 0 ;
                                        break ;
                                    }
                                    default : {
                                        system( "cls" ) ;
                                        cout << "    ID LOCAL        :  " << CUSTOMER [ j ] .IDL << "\n" ;
                                        cout << "    ID GLOBAL       :  " << CUSTOMER [ j ] .IDG << "\n\n" ;
                                        cout << "    FIRST NAME      :  " << CUSTOMER [ j ] .FIRST_NAME << "\n" ;
                                        cout << "    LAST NAME       :  " << CUSTOMER [ j ] .LAST_NAME << "\n\n" ;
                                        cout << "    DATE OF BIRTH   :  " << CUSTOMER [ j ] .DDATE_OF_BIRTH.DDAY << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.MMONTH << "/" << CUSTOMER [ j ]  .DDATE_OF_BIRTH.YYEAR << "\n\n" ;
                                        cout << "    CURRENT CITY    :  " << CUSTOMER [ j ] .LOCATION.CITY << "\n" ;
                                        cout << "    CURRENT COUNTRY :  " << CUSTOMER [ j ] .LOCATION.COUNTRY << "\n\n" ;
                                        cout << "    PRESS EITHER A OR D TO MOVE \n\n" ;
                                        cout << "            " << j + 1 << "/" << custommaxx ;
                                        break ;
                                    }
                                }
                            }
                            okp = 2 ;
                            break ;
                        }
                        case 32 :{
                            okp = 3 ;
                        }
                        case 27 : {
                            system ( "cls" ) ;
                            cout << " ---------------------------------------\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                            cout << " |        (1)               (2)        |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                            cout << " |        (3)              (4)         |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " |                                     |\n" ;
                            cout << " ---------------------------------------\n" ;
                            okp = 2 ;
                            break;
                        }
                        default : {
                            if ( opp != 27 ) {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " | SEARCH FOR CUSTOMER   ADD CUSTOMER  |\n" ;
                                cout << " |        (1)               (2)        |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |  REMOVE CUSTOMER  SEE ALL CUSTOMERS |\n" ;
                                cout << " |        (3)              (4)         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |      KEY PRESSED IS NOT 1/2/3/4     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                            }
                            break;
                        }
                    }
                } while ( opp != 27 && opp != 3 ) ;
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                okp = 2 ;
                break;
            }
            case '2' : {
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " | SEARCH FOR AIRPLANE   ADD AIRPLANE  |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |  REMOVE AIRPLANE  SEE ALL AIRPLANES |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                char opp = 0 ;
                do {
                    opp = getch ( ) ;
                    switch ( opp ) {
                        case '1' : {

                        }
                        case '2' : {

                        }
                        case '3' : {

                        }
                        case '4' : {

                        }
                        case 27 : {

                        }
                        default : {
                            if ( opp != 27 ) {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " | SEARCH FOR AIRPLANE   ADD AIRPLANE  |\n" ;
                                cout << " |        (1)               (2)        |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |  REMOVE AIRPLANE  SEE ALL AIRPLANES |\n" ;
                                cout << " |        (3)              (4)         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |      KEY PRESSED IS NOT 1/2/3/4     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                            }

                            break;
                        }
                    }
                } while ( opp != 27 && opp != 3 ) ;
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                op = 27 ;
                break;
            }
            case '3' : {
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " | SEARCH FOR EMPLOYEE   ADD EMPLOYEE  |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |  REMOVE EMPLOYEE   SORT EMPLOYEES   |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                char opp = 0 ;
                do {
                    opp = getch ( ) ;
                    switch ( opp ) {
                        case '1' : {

                        }
                        case '2' : {

                        }
                        case '3' : {

                        }
                        case '4' : {

                        }
                        case 32 :{
                            okp = 3 ;
                        }
                        case 27 : {

                        }
                        default : {
                            if ( opp != 27 ) {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " | SEARCH FOR EMPLOYEE   ADD EMPLOYEE  |\n" ;
                                cout << " |        (1)               (2)        |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |  REMOVE EMPLOYEE   SORT  EMPLOYEES  |\n" ;
                                cout << " |        (3)              (4)         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |      KEY PRESSED IS NOT 1/2/3/4     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                            }
                            break;
                        }
                    }
                } while ( opp != 27 && opp != 3 ) ;
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                op = 27 ;
                break;
            }
            case '4' : {
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |  SEE FULL PROGRAMME     ADD FLIGHT  |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |   REMOVE FLIGHT    REGISTER TICKET  |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                char opp = 0 ;
                do {
                    opp = getch ( ) ;
                    switch ( opp ) {
                        case '1' : {

                        }
                        case '2' : {

                        }
                        case '3' : {

                        }
                        case '4' : {
                        }
                        case 32 :{
                            okp = 3 ;
                        }
                        case 27 : {

                        }
                        default : {
                            if ( opp != 27 ) {
                                system ( "cls" ) ;
                                cout << " ---------------------------------------\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |  SEE FULL PROGRAMME     ADD FLIGHT  |\n" ;
                                cout << " |        (1)               (2)        |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |   REMOVE FLIGHT    REGISTER TICKET  |\n" ;
                                cout << " |        (3)              (4)         |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " |      KEY PRESSED IS NOT 1/2/3/4     |\n" ;
                                cout << " |                                     |\n" ;
                                cout << " ---------------------------------------\n" ;
                            }
                            break;
                        }
                    }
                } while ( opp != 27 && opp != 3 ) ;
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                op = 27 ;
                break;
            }
            case 27 : {
                system ( "cls" ) ;
                cout << " ---------------------------------------\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                cout << " |        (1)               (2)        |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                cout << " |        (3)              (4)         |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " |                                     |\n" ;
                cout << " ---------------------------------------\n" ;
                break;
            }
            case 32 : {
                okp = 3 ;
                break;
            }
            default : {
                if ( op != 27 ){
                    system ( "cls" ) ;
                    cout << " ---------------------------------------\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |     CUSTOMERS         AIRPLANES     |\n" ;
                    cout << " |        (1)               (2)        |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |     EMPLOYEES      FLIGHT PROGRAMME |\n" ;
                    cout << " |        (3)              (4)         |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " |      KEY PRESSED IS NOT 1/2/3/4     |\n" ;
                    cout << " |                                     |\n" ;
                    cout << " ---------------------------------------\n" ;
                }
            }
        }
    }
    system ("cls") ;
    cout << " ---------------------------------------\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |          HAVE A GOOD DAY!           |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " |                                     |\n" ;
    cout << " ---------------------------------------\n" ;
    getch();
    abort();
}
/*time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int DDAY = aTime->tm_mDDAY;
        int MMONTH = aTime->tm_mon + 1;
        int YYEAR = aTime->tm_YYEAR + 1900;
        j = rand ( ) % 30 + DDAY ;
        if ( MMONTH < 8 ) {
            if ( MMONTH % 2 == 0 ){
                if ( MMONTH == 2 ) {
                    if ( j + DDAY > 28 ) {
                        custi<< j + DDAY - 28 << " " << MMONTH + 1 << " " << YYEAR << " " ;
                    }
                    else
                        custi<< j + DDAY << " " << MMONTH << " " << YYEAR << " " ;
                }
                else
                {
                    if ( j + DDAY > 30 )
                        custi<< j + DDAY - 30 << " " << MMONTH + 1 << " " << YYEAR << " " ;
                    else
                     custi<< j + DDAY << " " << MMONTH << " " << YYEAR << " " ;
                }
            }
            else
            {   if ( j + DDAY > 31 )
                    custi<< j + DDAY - 31 << " " << MMONTH + 1 << " " << YYEAR << " " ;
                else
                    custi<< j + DDAY << " " << MMONTH << " " << YYEAR << " " ;
            }
        }
        else
        {
           if ( MMONTH % 2 == 0 ){
                if ( MMONTH == 12 ) {
                    if ( j + DDAY > 31 ) {
                        custi<< j + DDAY - 31 << " " << 1 << " " << YYEAR + 1 << " " ;
                    }
                }
                else
                {
                    if ( j + DDAY > 31 ) {
                        custi<< j + DDAY - 31 << " " << MMONTH + 1 << " " << YYEAR << " " ;
                    }
                }
            }
            else
            {
                  if ( j + DDAY > 30 ) {
                        custi<< j + DDAY - 30 << " " << MMONTH + 1 << " " << YYEAR << " " ;
                    }
            }
        }*/
