#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string vectorToString(vector <string> vetor) {
  string word = "";
  
  for(string value: vetor) {
    word += value;
  }

  return word;
}

vector<string> stringToVector(string word) {
  vector<string> palavra;

  for(char c: word) {
    palavra.push_back(string(1, c));
  }

  return palavra;
}

vector<string> decimalToBase(int num, int base) {
  int resto = 1; //Qualquer valor diferente de zero
  vector <string> baseNumber;

  while (true) {
    resto = num % base;
    baseNumber.insert(baseNumber.begin(), to_string(resto));
    num = num/base;

    if(num == 0 || num == 1)
      break;
  }

  if(num)
    baseNumber.insert(baseNumber.begin(), to_string(num));
   
  return baseNumber;
}

int baseToDecimal(vector<string> baseNum, int base) {
  int soma = 0;
  
  for(int i = 0; i < baseNum.size(); i++) {
    soma += (stoi(baseNum[i]))*pow(base, baseNum.size() - 1 - i);
  }

  return soma;
}

vector<string> decimalToHexa(int num) {
  char hexaCode[6] = {'A','B','C','D','E','F'};

  vector <string> code = decimalToBase(num, 16);

  for(size_t i = 0; i < code.size(); i++) {
    int numBit = stoi(code[i]);
    if(numBit >= 10) 
      code[i] = hexaCode[numBit - 10];
  }

  return code;
}

int hexaDecToInt(vector<string> hexaCode) {

  for(size_t i = 0; i < hexaCode.size(); i++) {
    if(hexaCode[i][0] >= 'A' && hexaCode[i][0] <= 'F') {
      hexaCode[i] = to_string(hexaCode[i][0] - 55);
    }
  }

  return baseToDecimal(hexaCode, 16);
}

int main(){
  
  int baseEntrada, baseSaida;
  string value, saida;

  cout << "|Base de entrada: ";
  cin >> baseEntrada;

  cout << "|Base de saída: ";
  cin >> baseSaida;

  cout << "|Valor: ";
  cin >> value;

  //Caso seja decimal para bases
  if(baseEntrada == 10) {
    if(baseSaida == 16) 
      saida = vectorToString(decimalToHexa(stoi(value)));
    else 
      saida = vectorToString(decimalToBase(stoi(value), baseSaida));
  }else if (baseEntrada == 16) {
    saida = to_string(hexaDecToInt(stringToVector(value)));
    //Caso a base de saída seja outra
    if(baseSaida != 10) 
      saida = vectorToString(decimalToBase(stoi(saida), baseSaida)); 
  }else /*Base qualquer*/ {
    saida = to_string(baseToDecimal(stringToVector(value), baseEntrada));
    if(baseSaida != 16)
      saida = vectorToString(decimalToBase(stoi(saida), baseSaida));
    else 
      saida = vectorToString(decimalToHexa(stoi(saida)));
  }
      
  cout << value << " | " << saida << endl;
  
  return 0;
}