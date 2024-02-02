
// https://github.com/kayd0912/math/blob/main/math.cpp

/*##### Introduction #######
# - Source code: MATH.cpp  #
# - Author(s):  @kayd0912  #
# - Version: 0.1.2 (Alpha) #
##########################*/

/*################################## Note ####################################
# - You are viewing the source code of all the math functions                #
# - Don't change anything of this code because this can make the functions   #
# cannot working properly                                                    #
# - There are some functions started with "p_" that mean PRIVATE functions.  #
# They're built just for PUBLIC functions to work conveniently               #
# - Don't use PRIVATE functions because they're very complicated             #
# - Most numbers are stored as strings in order to calculate with huge       #
# numbers                                                                    #
# - Any problems? Report them here : https://github.com/kayd0912/math/issues #
############################################################################*/

/*################################ MATH.CPP ################################*/

// Libraries
#include <bits/stdc++.h>
using namespace std;

// Convert a character to a number
int p_ctoi(char x) {
    return x-48;
}

// Take the copy of <num> character(s) start from <target> index of string <root>
string p_copy(string root, long long target, long long num) {
    string result = "";
    for (long long i=target; i<target+num; i++) {
        result += root[i];
    }
    return result;
}

// Push <num> char(s) <c> in front of the string <x>
void p_fpush(string& x, string c, long long num) {
    for (long long i=0; i<num; i++) {
       x = c + x;
    }
}

// Add two numbers (just apply when a>0, b>0 and a>b)
string p_add(string a, string b) {
    string sum="";
    int tmp=0, v;
    for (int i=a.size()-1; i>=0; i--) {
        v = p_ctoi(a[i]) + p_ctoi(b[i]) + tmp;
        sum = to_string(v%10) + sum;
        tmp = (int)(v/10);
    }
    while (sum[0] == '0' && sum.size() != 1) {
        sum.erase(sum.begin());
    }
    return sum;
}

// Subtract two numbers (just apply when a>0, b>0 and a>b)
string p_sub(string a, string b) {
    string sum="";
    int tmp=0, v;
    for (int i=a.size()-1; i>=0; i--) {
        v = p_ctoi(a[i]) - p_ctoi(b[i]) - tmp;
        if (v < 0) {
            v += 10;
            tmp = 1;
        } else {
            tmp = 0;
        }
        sum = to_string(v%10) + sum;
    }
    while (sum[0] == '0' && sum.size() != 1) {
        sum.erase(sum.begin());
    }
    return sum;
}

// Add two numbers
string add(string a, string b) {
    string ar, br;
    if (a[0] == '-') {
        ar = p_copy(a, 1, a.size()-1);
    } else {
        ar = a;
    }
    if (b[0] == '-') {
        br = p_copy(b, 1, b.size()-1);
    } else {
        br = b;
    }
    if (ar.size() < br.size()) {
        swap(ar, br);
    }
    p_fpush(ar, "0", 1);
    p_fpush(br, "0", ar.size() - br.size());
    if (a[0] != '-') {
        if (b[0] != '-') {
            return p_add(ar, br);
        } else {
            if (ar > br) {
                return p_sub(ar, br);
            } else {
                return "-" + p_sub(br, ar);
            }
        }
    } else {
        if (b[0] != '-') {
            if (ar > br) {
                return "-" + p_sub(ar, br);
            } else {
                return p_sub(br, ar);
            }
        } else {
            return "-" + p_add(ar, br);
        }
    }
}

// Subtract two numbers
string sub(string a, string b) {
    string ar, br;
    if (a[0] == '-') {
        ar = p_copy(a, 1, a.size()-1);
    } else {
        ar = a;
    }
    if (b[0] == '-') {
        br = p_copy(b, 1, b.size()-1);
    } else {
        br = b;
    }
    if (ar.size() < br.size()) {
        swap(ar, br);
    }
    p_fpush(ar, "0", 1);
    p_fpush(br, "0", ar.size() - br.size());
    if (a[0] != '-') {
        if (b[0] != '-') {
            if (ar > br) {
                return p_sub(ar, br);
            } else {
                return "-" + p_sub(br, ar);
            }
        } else {
            return p_add(ar, br);
        }
    } else {
        if (b[0] != '-') {
            return "-" + p_add(ar, br);
        } else {
            if (ar > br) {
                return "-" + p_sub(ar, br);
            } else {
                return p_sub(br, ar);
            }
        }
    }
}

// Multiply two numbers (just apply when a>0 and b>0)
string p_mul(string a, string b) {
    string sum="0", i="0";
    if (i.size() < b.size()) {
        p_fpush(i, "0", b.size() - i.size());
    }
    while (i<b) {
        sum = add(sum, a);
        i = add(i, "1");
        if (i.size() < b.size()) {
            p_fpush(i, "0", b.size() - i.size());
        }
    }
    return sum;
}

// Multiply two numbers
string mul(string a, string b) {
    string ar, br;
    if (a[0] == '-') {
        ar = p_copy(a, 1, a.size()-1);
    } else {
        ar = a;
    }
    if (b[0] == '-') {
        br = p_copy(b, 1, b.size()-1);
    } else {
        br = b;
    }
    if ((a[0] != '-' && b[0] != '-') || (a[0] == '-' && b[0] == '-')) {
        return p_mul(ar, br);
    } else {
        return "-" + p_mul(ar, br);
    }
}

// Calculate the factorial of n (n!)
// NOTE : It can just work only if n <= 250
string factorial(long long n) {
    string sum="1";
    for (long long i=1; i<=n; i++) {
        sum = mul(sum, to_string(i));
    }
    return sum;
}

// Examples
int main() {
    long long n;
    cin >> n;
    cout << factorial(n);
    return 0;
}

/*#### END OF FILE ####*/
