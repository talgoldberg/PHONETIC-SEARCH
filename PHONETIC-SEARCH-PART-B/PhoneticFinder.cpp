//
// AUTHORS: Avichai and Tal
//

#include <stdexcept>

#include "PhoneticFinder.hpp"
using namespace std;


namespace phonetic {
    string find(string text, string s) {
        if((text==" ")||(text=="")||(s==" ")||(s==""))   throw  std::out_of_range  ("Did not find the word "+s+" in the text");
      s=help(s);
        for (int i = 0; i < text.length(); i++) {
            int j = 0;

            while (text[i] != ' '||j == s.length()) {

                if (j != s.length()) {
                    if ((s[j] == text[i]) || (s[j] == text[i] + 32) || (s[j] + 32 == text[i])) {
                        j++;
                        i++;
                    } else if (((s[j] == 't' && text[i] == 'd') || (s[j] == 'd' && text[i] == 't') ||
                                (s[j] == 'T' && text[i] == 'd') || (s[j] == 'd' && text[i] == 'T') ||
                                (s[j] == 'D' && text[i] == 'T') || (s[j] == 'T' && text[i] == 'D') ||
                                (s[j] == 'D' && text[i] == 't') || (s[j] == 't' && text[i] == 'D') || (s[j] == 'b' &&
                                                                                                       (text[i] ==
                                                                                                        'f' ||
                                                                                                        text[i] ==
                                                                                                        'p' ||
                                                                                                        text[i] ==
                                                                                                        'P' ||
                                                                                                        text[i] ==
                                                                                                        'F')) ||
                                (s[j] == 'f' &&
                                 (text[i] == 'b' || text[i] == 'p' || text[i] == 'B' || text[i] == 'P')) ||
                                (s[j] == 'p' &&
                                 (text[i] == 'b' || text[i] == 'B' || text[i] == 'F' || text[i] == 'f')) ||
                                (s[j] == 'P' &&
                                 (text[i] == 'b' || text[i] == 'F' || text[i] == 'B' || text[i] == 'f')) ||
                                (s[j] == 'B' &&
                                 (text[i] == 'F' || text[i] == 'p' || text[i] == 'f' || text[i] == 'P')) ||
                                (s[j] == 'F' &&
                                 (text[i] == 'b' || text[i] == 'p' || text[i] == 'B' || text[i] == 'P')))) {
                        j++;
                        i++;
                    } else if (((s[j] == 'v' && text[i] == 'w') || (s[j] == 'w' && text[i] == 'v') ||
                                (s[j] == 'V' && text[i] == 'w') || (s[j] == 'w' && text[i] == 'V') ||
                                (s[j] == 'W' && text[i] == 'V') || (s[j] == 'V' && text[i] == 'W') ||
                                (s[j] == 'W' && text[i] == 'v') || (s[j] == 'v' && text[i] == 'W') || (s[j] == 'q' &&
                                                                                                       (text[i] ==
                                                                                                        'c' ||
                                                                                                        text[i] ==
                                                                                                        'k' ||
                                                                                                        text[i] ==
                                                                                                        'K' ||
                                                                                                        text[i] ==
                                                                                                        'C')) ||
                                (s[j] == 'c' &&
                                 (text[i] == 'q' || text[i] == 'k' || text[i] == 'Q' || text[i] == 'K')) ||
                                (s[j] == 'k' &&
                                 (text[i] == 'q' || text[i] == 'Q' || text[i] == 'C' || text[i] == 'c')) ||
                                (s[j] == 'K' &&
                                 (text[i] == 'q' || text[i] == 'C' || text[i] == 'Q' || text[i] == 'c')) ||
                                (s[j] == 'Q' &&
                                 (text[i] == 'C' || text[i] == 'k' || text[i] == 'c' || text[i] == 'K')) ||
                                (s[j] == 'C' &&
                                 (text[i] == 'q' || text[i] == 'k' || text[i] == 'Q' || text[i] == 'K')))) {
                        j++;
                        i++;
                    } else if (((s[j] == 'g' && (text[i] == 'j' || text[i] == 'J')) ||
                                (s[j] == 'j' && (text[i] == 'g' || text[i] == 'G')) ||
                                (s[j] == 'G' && (text[i] == 'J' || text[i] == 'j')) ||
                                (s[j] == 'J' && (text[i] == 'G' || text[i] == 'g')) ||
                                (s[j] == 'z' && (text[i] == 's' || text[i] == 'S')) ||
                                (s[j] == 's' && (text[i] == 'z' || text[i] == 'Z')) ||
                                (s[j] == 'Z' && (text[i] == 'S' || text[i] == 's')) ||
                                (s[j] == 'S' && (text[i] == 'Z' || text[i] == 'z')))) {
                        j++;
                        i++;
                    } else if (((s[j] == 'o' && (text[i] == 'u' || text[i] == 'U')) ||
                                (s[j] == 'u' && (text[i] == 'o' || text[i] == 'O')) ||
                                (s[j] == 'U' && (text[i] == 'O' || text[i] == 'o')) ||
                                (s[j] == 'O' && (text[i] == 'U' || text[i] == 'u')) ||
                                (s[j] == 'i' && (text[i] == 'y' || text[i] == 'Y')) ||
                                (s[j] == 'y' && (text[i] == 'i' || text[i] == 'I')) ||
                                (s[j] == 'I' && (text[i] == 'Y' || text[i] == 'y')) ||
                                (s[j] == 'Y' && (text[i] == 'I' || text[i] == 'i')))) {
                        j++;
                        i++;
                    } else {
                        j = 0;
                        i = space2(text, i);
                        if (i == -1) throw std::out_of_range("Did not find the word " + s + " in the text");
                    }
                } else {
                    if (i < text.length()){
                        if (text[i] != ' ') {
                            j = 0;
                            i = space2(text, i);
                            if (i == -1) throw std::out_of_range("Did not find the word " + s + " in the text");
                        }
                }
                        int indexHelp = i - s.length();
                        string ans = "";
                        for (int k = indexHelp, j = 0; j < s.length(); k++, j++) {

                            ans = ans + text[k];
                        }
                        return ans;

                    }

                }

        }
        throw  std::out_of_range  ("Did not find the word "+s+" in the text");
            }

    int space2(string text, int index) {
        for (int i = index; i < text.length(); i++) {
            if (text[i] == ' ') return i;

        }
        return -1;

    }
    string help (string s){
        string ans;
        for(int i=0;i<s.length();i++){
          if(s[i]!=' ')
              ans=ans+s[i];
        }
        return ans;
    }


////////////////////////////////////////////////////////////////////////////////////
      /*  bool equal(string a,string b){
            for(int i=0; i<a.length(); i++){
                if(a[i]!=b[i])
                    return false;

            }
            return true;
        }

        string find(string text, string s) {
            int index=0;
            string help="";
            string help1="";
            string help2="";
            string ans="";
            string temp="";
            for (int i = 0; i < text.length(); i++) {
                if(text[i]==' ')
                    index=i;
            }

            for (int i = 0; i < text.length(); i++) {
                if(text[i]!=' ') {
                    help=help+text[i];
                }
                if(text[i]==' ') {
                    temp=help;
                    for(int k=0; k<help.length(); k++) {
                        if(help[k]<97)
                            help1=help1+(char)(help[k]+32);
                        else
                            help1=help1+help[k];
                    }
                    for (int k1 = 0; k1 < s.length(); k1++) {
                        if(s[k1]<97)
                            help2=help2+(char)(s[k1]+32);
                        else
                            help2=help2+s[k1];

                    }
                    s=help2;
                    help=help1;
                    help1="";
                    help2="";
                    for (int x = 0; x < help.length(); x++) {

                        if(x<s.length()) {
                            if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                                ans=ans+help[x];
                            if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                                ans=ans+help[x];
                            if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                                ans=ans+help[x];
                            if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                                ans=ans+help[x];
                            if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                                ans=ans+help[x];
                            if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                                ans=ans+help[x];
                            if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                                ans=ans+help[x];
                            if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                                ans=ans+help[x];
                            if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                                ans=ans+help[x];
                            if(s[x]==help[x])
                                ans=ans+help[x];
                            if(equal(help,ans))
                                return temp;

                        }
                    }


                    if(!equal(help,ans))
                        ans="";
                    help="";
                }
            }

            if(index>0){
                help="";
                for(int t=index+1; t<text.length(); t++) {
                    help=help+text[t];

                }
                temp=help;
                for(int k=0; k<help.length(); k++) {
                    if(help[k]<97)
                        help1=help1+(char)(help[k]+32);
                    else
                        help1=help1+help[k];
                }
                for (int k1 = 0; k1 < s.length(); k1++) {
                    if(s[k1]<97)
                        help2=help2+(char)(s[k1]+32);
                    else
                        help2=help2+s[k1];

                }
                s=help2;
                help=help1;
                help1="";
                help2="";

                for (int x = 0; x < help.length(); x++) {

                    if(x<s.length()) {
                        if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                            ans=ans+help[x];
                        if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                            ans=ans+help[x];
                        if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                            ans=ans+help[x];
                        if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                            ans=ans+help[x];
                        if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                            ans=ans+help[x];
                        if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                            ans=ans+help[x];
                        if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                            ans=ans+help[x];
                        if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                            ans=ans+help[x];
                        if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                            ans=ans+help[x];
                        if(s[x]==help[x])
                            ans=ans+help[x];
                        if(equal(help,ans))
                            return temp;

                    }
                }


            }
            if(index==0){
                help="";
                for(int t=0; t<text.length(); t++) {
                    help=help+text[t];

                }
                temp=help;
                for(int k=0; k<help.length(); k++) {
                    if(help[k]<97)
                        help1=help1+(char)(help[k]+32);
                    else
                        help1=help1+help[k];
                }
                for (int k1 = 0; k1 < s.length(); k1++) {
                    if(s[k1]<97)
                        help2=help2+(char)(s[k1]+32);
                    else
                        help2=help2+s[k1];

                }
                s=help2;
                help=help1;
                help1="";
                help2="";

                for (int x = 0; x < help.length(); x++) {

                    if(x<s.length()) {
                        if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                            ans=ans+help[x];
                        if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                            ans=ans+help[x];
                        if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                            ans=ans+help[x];
                        if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                            ans=ans+help[x];
                        if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                            ans=ans+help[x];
                        if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                            ans=ans+help[x];
                        if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                            ans=ans+help[x];
                        if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                            ans=ans+help[x];
                        if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                            ans=ans+help[x];
                        if(s[x]==help[x])
                            ans=ans+help[x];
                        if(equal(help,ans))
                            return temp;

                    }
                }
            }

            return temp;

        }*/
}
