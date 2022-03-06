
#include<iostream>
#include<math.h>

using namespace std;
// 

float nghiemLon(float a, float b, float c){
    return (-b+sqrt(b*b-4*a*c))/(2*a);
}

float nghiemNho(float a, float b, float c){
    return (-b-sqrt(b*b-4*a*c))/(2*a);
}
float delta(float a,float b,float c){
    return b*b-4*a*c;
}

void GiaiPTB2(){
    cout << "nhap cac gia tri a,b,c"<< endl;
    float a,b,c;
    cin >> a >> b >> c;
    if(a==0){
        if(b==0){
            if(c==0){
                cout<<"PT co vo so nghiem";
            }
            else{
                cout << "PT vo nghiem";
            }
        }
        else{
            cout <<" PT co nghiem" << -c/b ;
        }
    }
    else{
        if(delta(a,b,c) <0){
            cout <<"PT vo nghiem";
        }
        else if(delta(a,b,c)==0){
            cout <<
        }
        else{
            cout <<"Pt co nghiem x1, x2 la"<< nghiemLon(a,b,c) << nghiemNho(a,b,c);
        }
    }
}

int main(){
    GiaiPTB2();
    return 0;
}