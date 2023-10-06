#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    double pontos_;
    int i = 1;
    string nome_usuario;
    cout << "Digite seu nickname: ";
    cin >> nome_usuario;
    cout << "***************************************************************************************" << endl;
    cout << nome_usuario << ", " << " Seja bem vindo ao jogo da adivinhação!" << endl; 
    cout << "Regras do jogo: " << endl;
    cout << "O número secreto será sempre um número aleatório entre 0 e 100 " << endl;
    cout << "Você pode jogar múltiplas vezes, e será contado no final de cada rodada sua pontuação." << endl;
    cout << "No final do jogo (Se voce jogou várias rodadas), aparecerá a pontuação total." << endl;    
    cout << "****************************************************************************************" << endl;
    
    int num_de_tentativas;
    while(1){
    while(1){
    cout << "Escolha o nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)." << endl;
    char nivel_de_dificuldade;
    cin >> nivel_de_dificuldade;

    if(nivel_de_dificuldade == 'F'){
        num_de_tentativas = 15;
        break;
    }else if(nivel_de_dificuldade == 'M'){
        num_de_tentativas = 10;
        break;
    }else if(nivel_de_dificuldade == 'D'){
        num_de_tentativas = 5;
        break;
    }else{
        cout << "Digite uma opção válida" << endl;
    }
    }
    srand(time(NULL));
    const int NUMBER_SECRET = rand() % 100;
    int chute;
    bool nao_acertou = true; 
    double pontos = 100.0;
    int tentativas = 0;
    
    for(tentativas = 1;tentativas <= num_de_tentativas;tentativas++){
    cout << "Tentativa " << tentativas << ": " << endl;
    bool numero_valido = false;
    while(numero_valido == false){
    cout << "Qual seu chute?" << endl;
    cin >> chute;
      if(chute < 0 || chute > 100){
        cout << "Digite um valor válido entre 0 e 100." << endl;
      }else{
        numero_valido = true;
      }
    }

    double pontos_perdidos = abs(chute - NUMBER_SECRET) / 2.0;
    pontos = pontos - pontos_perdidos;

    bool acertou = chute == NUMBER_SECRET;
    bool menor = chute > NUMBER_SECRET;

    if(acertou){
        cout << endl;
        cout << "Fim de jogo" << endl;
        cout<<"Parabéns, você acertou"<<endl;
        nao_acertou = false;
        break;
    }else if(menor){
        cout<<"O número secreto é menor."<<endl;
    }else{
        cout<<"O número secreto é maior."<<endl;
    }
    }
    if(nao_acertou){
        cout << endl;
        cout << "Fim de jogo" << endl;
        cout << "Você perdeu!" << endl;
    }
    else{
        cout << "Número de tentativas: " << tentativas << endl;
        cout << "Sua pontuação foi de: " << pontos << " Pontos" << endl;
    }
    cout << "O número secreto era: " << NUMBER_SECRET << endl;
    cout << "******************************" << endl;
    char jogar_novamente;
    cout << "Você quer jogar novamente? S/N" << endl;
    cin >> jogar_novamente;
    if(jogar_novamente == 'N' || jogar_novamente == 'n'){
        pontos_ += pontos;
        break;
    }else{
        i++;
        pontos_ += pontos;
    }
    }
    cout << "*********************************************" << endl;
    cout << "Você jogou " << i << " jogos." << endl;
    cout << "Sua pontuação total foi de: " << pontos_ << " Pontos." << endl;
    

    return 0;
}
