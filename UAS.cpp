#include <iostream>
#include <cmath>
using namespace std;

float pearson(float[], float[]);
string kethub(float);
string def(float);

int main(){
	float x[100],y[100];
	float codet, r;
	
	cout << "Pearson correlation program" << endl;
	cout << endl;
	for (int i = 1; i <= 3; i++){
		cout << "Input X-" << i << " : "; cin >> x[i];
		cout << "Input Y-" << i << " : "; cin >> y[i];
		if (x[i] < 0 || y[i] < 0){
			cout << "Nilai x atau y tidak boleh negatif" << endl;
			i = i-1;
		}
		cout << endl;
		
	}
	
	cout << "r : " << pearson(x, y) << endl;
	codet = pearson(x, y);
	codet = pow(codet,2) * 100/100;
	cout << "Koefisien determinasi : " << codet << endl;
	r = pearson(x, y);
	cout << "Hubungan Korelasi : " << kethub(r) << endl;
	cout << def(r) << endl;
}

float pearson(float _x[], float _y[]){
	float result, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	for (int i = 1; i <= 3; i++){
		temp1 = temp1 + (_x[i] * _y[i]);
		temp2 = temp2 + _x[i];
		temp3 = temp3 + _y[i];
		temp4 = temp4 + pow(_x[i],2);
		temp5 = pow(temp2,2);
		temp6 = temp6 + pow(_y[i],2);
		temp7 = pow(temp3,2);
	}
	temp1 = 3*temp1;
	temp4 = 3*temp4;
	temp6 = 3* temp6;
	temp4 = temp4-temp5;
	temp4 = sqrt(temp4);
	temp6 = temp6-temp7;
	temp6 = sqrt(temp6);
	result = (temp1 - (temp2*temp3)) / (temp4 * temp6);
	return result;
}

string kethub(float _person){
	string hub;
	if (_person >= 0  ){
		hub = "Hubungan korelasinya diabaikan";
	}
	if (_person > 0.10  ){
		hub = "Hubungan korelasinya rendah";
	}
	if (_person > 0.30  ){
		hub = "Hubungan korelasinya moderat";
	}
	if (_person > 0.50  ){
		hub = "Hubungan korelasinya sedang";
	}
	if (_person > 0.70 ){
		hub = "Hubungan korelasinya sangat kuat";
	}
	return hub;
}

string def(float _persn){
	string index;
	if (_persn > 0){
		index = "Hubungan antara variable X dan Y adalah positif, dimana jika nilai X bertambah, maka nilai Y pun akan bertambah, dan juga sebaliknya";
	}	
	else if (_persn == 0){
		index = "Tidak ada hubungan antara variable X dan Y";
	}	
	else if (_persn < 0){
		index = "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai X bertambah, maka nilai Y akan mengecil, dan juga sebaliknya";
	}	
	return index;
	
}


