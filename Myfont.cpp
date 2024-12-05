#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//width = 5
//height = 5
// Operater Overloading may be used over the join function
int i, j;
class stroke {
    public:
        char star[5][5];
        stroke(){ //constructor
            for(i = 0; i<5; i++)
                for(j = 0; j<5; j++)
                    star[i][j] = ' ';
        }
        void line(int r1, int c1, int r2, int c2){ //create line 
            float inc = 1;
            if(r1-r2 != 0 ) inc = 5 + (float) (c2-c1)/(r2-r1);
            if(inc != (int) inc) inc *= 2;
            for(i = r1*5 + c1; i <= r2*5 + c2; i += inc)
                star[i/5][i%5] = '*'; 
        }
};

stroke join(vector<stroke> strokes){
    stroke s_res;
    int k;
    for(i = 0; i<5; i++)
        for(j = 0; j<5; j++)
            for(stroke s : strokes)
                if(s.star[i][j] == '*')
                    s_res.star[i][j] = '*';
    return s_res;
}

int main() {
    stroke l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,f;
    l1.line(0,0,4,0); //left vertical line
    l2.line(0,0,0,4); //top horizontal line
    l3.line(0,2,4,0); //left slant 1
    l4.line(0,2,4,4); //right slant 1
    l5.line(2,0,2,4); //mid horizontal line
    l6.line(4,0,4,4); //bottom horizontal line
    l7.line(0,4,4,4); //right vertical line
    l8.line(0,2,4,2); //mid vertical line
    l9.line(0,4,2,2); //left slant 2
    l10.line(0,0,2,2); //right slant 2
    l11.line(2,2,4,4); //right slant 3
    l12.line(2,2,4,0); //left slant 3
    char l;
    string text;
    cout<<"Enter text: ";
    getline(cin,text);
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    cout<<"\n   "<<text<<" in big font is\n\n";
    stroke big_fonts[text.length()];
    for(int i = 0;i<text.length();i++){
        l = text[i];
        l = (char) toupper(l);
        switch(l){
            case('A'):
                f = join({l1,l2,l5,l7}); 
                f.star[0][0] = f.star[0][4] = ' ';
                break;
            case('B'):
                f = join({l1,l2,l5,l6});
                f.star[1][4] = f.star[3][4] = '*';
                f.star[0][4] = f.star[2][4] = f.star[4][4] = ' ';
                break;
            case('C'):
                f = join({l1,l2,l6});
                f.star[0][0] = f.star[4][0] = ' ';
                break;
            case('D'):
                f = join({l1,l2,l6,l7});
                f.star[0][4] = f.star[4][4] = ' ';
                break;
            case('E'):
                f = join({l1,l2,l5,l6});
                break;
            case('F'):
                f = join({l1,l2,l5});
                break;
            case('G'):
                f = join({l1,l2,l6,l7,l5});
                f.star[1][4] = f.star[2][1] = ' ';
                break;
            case('H'):
                f = join({l1,l5,l7});
                break;
            case('I'):
                f = join({l2,l6,l8});
                break;
            case('J'):
                f = join({l2,l8});
                f.star[4][0] = f.star[4][1] = '*';
                break;
            case('K'):
                f = join({l1,l9,l11});
                f.star[2][1] = '*';
                break;
            case('L'):
                f = join({l1,l6});
                break;
            case('M'):
                f = join({l1,l7,l9,l10});
                break;
            case('N'):
                f = join({l1,l7,l10,l11});
                break;
            case('O'):
                f = join({l1,l2,l7,l6});
                f.star[0][0] = f.star[0][4] = f.star[4][0] = f.star[4][4] = ' ';
                break;
            case('P'):
                f = join({l1,l2,l5});
                f.star[1][4] = '*';
                f.star[0][4] = f.star[2][4] = ' ';
                break;
            case('Q'):
                f = join({l1,l2,l11});
                f.star[0][4] = f.star[4][0] = f.star[2][2] = ' ';
                f.star[1][3] = f.star[2][3] = f.star[3][1] = f.star[3][2] = '*';
                break;
            case('R'):
                f = join({l1,l2,l5,l11});
                f.star[1][4] = '*';
                f.star[0][4] = f.star[2][4] = ' ';
                break;
            case('S'):
                f = join({l2,l5,l6});
                f.star[1][0] = f.star[3][4] = '*';
                f.star[0][0] = f.star[4][4] = ' ';
                break;
            case('T'):
                f = join({l2,l8});
                break;
            case('U'):
                f = join({l1,l7,l6});
                f.star[4][0] = f.star[4][4] = ' ';
                break;
            case('V'):
                f.star[0][0] = f.star[2][1] = f.star[4][2] = f.star[2][3] = f.star[0][4] = '*';
                break;
            case('W'):
                f = join({l1,l7,l11,l12});
                break;
            case('X'):
                f = join({l9,l10,l11,l12});
                break;
            case('Y'):
                f = join({l9,l10});
                f.star[3][2] = f.star[4][2] = '*';
                break;
            case('Z'):
                f = join({l2,l6,l9,l12});
                break;
            default:
                f = l0;
        }
        big_fonts[i] = f;
    }
    for(i = 0; i<5; i++){
        cout<<"   ";
        for(stroke s : big_fonts){
            for(j = 0; j<5; j++)
                cout<<s.star[i][j];
            cout<<"   ";
        }
        cout<<"\n";
    }
    return 0;
}
