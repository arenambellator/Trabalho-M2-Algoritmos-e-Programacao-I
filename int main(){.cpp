#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Variáveis gerais do programa
    int game=0, op, p, t, g, f, sortenum, resp;
    char sorte, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    
    // Loop principal do menu: continua até o usuário escolher Sair
    while(game==0){
        cout<<"           Menu De Jogos"<<endl<<endl<<endl<<"  => Digite o número Da Operação: "<<endl<<endl<<"  - 1 Jogo de adivinhação"<<endl<<endl<<"  - 2 Quiz de Conhecimentos Gerais"<<endl<<endl<<"  - 3 Sair"<<endl<<endl<<endl<<"  > ";
        cin>>op;
        
        // Direciona para o jogo escolhido pelo usuário
        switch(op){
            case 1:
                int r;
                
                // Gera um número aleatório entre -100 e 100
                srand(time(0));
                r = (rand() % (100 - (-100) + 1)) + (-100);
                
                cout<<endl<<endl<<"  - Tente advinhar o número aleatório gerado (de -100 a 100). Para sair digite o número: 360. Você tem 30 chances!";
                
                // Loop de tentativas: o jogador tem 30 chances
                for(int i=1; i<=31; i++){
                    
                    if(i<=30){
                        cout<<endl<<endl<<"Tentativa número: "<<i<<endl<<endl<<"  > ";
                        cin>>p;
                        
                        // Permite sair do jogo digitando 360
                        if(p==360){
                            break;
                            cout<<endl<<endl<<endl;
                        }
                        
                        // Verifica se o palpite está correto
                        if(p==r){
                            cout<<endl<<endl<<"  | Você acertou!"<<endl<<endl<<endl;
                            break;
                        }else{
                            cout<<endl<<endl<<"  | Tente Novamente!";
                        }
                        
                        // Dica 1 (a partir da 5ª tentativa): informa se o número é par ou ímpar
                        if(i>=5){
                            if(r%2==0){
                                cout<<endl<<"  / Dica 1: O número é par";
                            }else{
                                cout<<endl<<"  / Dica 1: O número é impar";
                            }
                        }
                        
                        // Dica 2 (a partir da 7ª tentativa): informa se o palpite está quente ou frio
                        // "Quente" significa que o palpite está a menos de 11 unidades do número correto
                        if(i>=7){
                            for(int d=1; d<=11; d++){
                                t=(p-d);
                                g=(p+d);
                                
                                if((t==r)&&(d<11)){
                                    cout<<endl<<"  / Dica 2: Está quente!";
                                    d=20;
                                }else if((g==r)&&(d<11)){
                                    cout<<endl<<"  / Dica 2: Está quente!";
                                    d=20;
                                }
                                
                                if(d==11){
                                    cout<<endl<<"  / Dica 2: Está frio!";
                                }
                            }
                        }
                        
                        // Dica 3 (a partir da 12ª tentativa): mostra a distância e direção até o número correto
                        if(i>=12){
                            f=p-r;
                            
                            if(f<0){
                                f=f*(-1);
                                cout<<endl<<"  / Dica 3: Seu palpite está a "<<f<<" números abaixo de distância da resposta";
                            }else if(f>0){
                                cout<<endl<<"  / Dica 3: Seu palpite está a "<<f<<" números acima de distância da resposta";
                            }
                        }
                        
                        // Na 20ª tentativa: oferece um efeito aleatório de sorte ao jogador
                        if(i==20){
                            cout<<endl<<endl<<endl<<"  ~ Você está a 10 tentativas de distância, deseja arriscar sua sorte e rolar um efeito aleatório?    s/n"<<endl<<endl<<"  > ";
                            cin>>sorte;
                            
                            if(sorte=(('s')||('S'))){
                                // Sorteia um número de 1 a 100 para definir o efeito
                                sortenum = (rand() % (100 - 1 + 1)) + 1;
                                
                                // 1-50: nada acontece
                                if(sortenum<=50){
                                    cout<<endl<<endl<<"  | Que azar!"<<endl<<"  | Nada aconteceu!";
                                // 51-90: revela se o número é positivo ou negativo
                                }else if((sortenum>50)&&(sortenum<=90)){
                                    if(r>=0){
                                        cout<<endl<<endl<<"  / Dica 4 O número é positivo ou zero!";
                                    }else{
                                        cout<<endl<<endl<<"  / Dica 4 O número é negativo!";
                                    }
                                // 91-100: reseta o jogo com um novo número aleatório
                                }else if((sortenum>90)&&(sortenum<=100)){
                                    r = (rand() % (100 - (-100) + 1)) + (-100);
                                    i=1;
                                    
                                    cout<<endl<<endl<<"  | O jogo foi resetado!";
                                }
                            }
                        }
                        
                    // Se esgotou as 30 tentativas, exibe derrota e revela o número
                    }else if (i==31){
                        cout<<endl<<endl<<"  | Você Perdeu!"<<endl<<"  | O número era: "<<r<<endl<<endl<<endl;
                    }
                }
            break;
            
            case 2:
            
                resp=0;
                
                cout<<endl<<endl<<"  - Quiz de conhecimentos gerais: tente acertar ao menos 5 questões para ganhar!"<<endl<<endl;
                
                // Cada bloco abaixo exibe uma pergunta, lê a resposta e verifica se está correta
                
                //Q1
                cout<<"\n\nQuestao 1:\nQual o maior planeta do Sistema Solar?:\n\nA)Saturno\nB)Netuno\nC)Jupiter\nD)Urano\n\nRESPOSTA:";
                cin>>q1;
                if (q1=='C'||q1=='c'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e C) Jupiter.\n";
                }
                
                //Q2
                cout<<"\n\nQuestao 2:\nQual pais possui a maior populacao do mundo?:\n\nA)India\nB)Estados Unidos\nC)Brasil\nD)China\n\nRESPOSTA:";
                cin>>q2;
                if (q2=='A'||q2=='a'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e A) India.\n";
                }
                
                //Q3
                cout<<"\n\nQuestao 3:\nQuem pintou a Mona Lisa?:\n\nA)Michelangelo\nB)Rafael\nC)Leonardo da Vinci\nD)Donatello\n\nRESPOSTA:";
                cin>>q3;
                if (q3=='C'||q3=='c'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e C) Leonardo da Vinci.\n";
                }
                
                //Q4
                cout<<"\n\nQuestao 4:\nQual o rio mais extenso do mundo?:\n\nA)Amazonas\nB)Nilo\nC)Yangtze\nD)Mississipi\n\nRESPOSTA:";
                cin>>q4;
                if (q4=='B'||q4=='b'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e B) Nilo.\n";
                }
                
                //Q5
                cout<<"\n\nQuestao 5:\nQual o elemento quimico de simbolo 'O'?:\n\nA)Ouro\nB)Osmio\nC)Oxigenio\nD)Onio\n\nRESPOSTA:";
                cin>>q5;
                if (q5=='C'||q5=='c'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e C) Oxigenio.\n";
                }
                
                //Q6
                cout<<"\n\nQuestao 6:\nEm que ano o homem pisou na Lua pela primeira vez?:\n\nA)1965\nB)1972\nC)1975\nD)1969\n\nRESPOSTA:";
                cin>>q6;
                if (q6=='D'||q6=='d'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e D) 1969.\n";
                }
                
                //Q7
                cout<<"\n\nQuestao 7:\nQual o menor pais do mundo?:\n\nA)Monaco\nB)San Marino\nC)Vaticano\nD)Liechtenstein\n\nRESPOSTA:";
                cin>>q7;
                if (q7=='C'||q7=='c'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e C) Vaticano.\n";
                }
                
                //Q8
                cout<<"\n\nQuestao 8:\nQuantos continentes existem na Terra?:\n\nA)5\nB)7\nC)6\nD)8\n\nRESPOSTA:";
                cin>>q8;
                if (q8=='B'||q8=='b'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e B) 7.\n";
                }
                
                //Q9
                cout<<"\n\nQuestao 9:\nQual o osso mais longo do corpo humano?:\n\nA)Umero\nB)Tibia\nC)Coluna vertebral\nD)Femur\n\nRESPOSTA:";
                cin>>q9;
                if (q9=='D'||q9=='d'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e D) Femur.\n";
                }
                
                //Q10
                cout<<"\n\nQuestao 10:\nQual a capital da Australia?:\n\nA)Sydney\nB)Melbourne\nC)Camberra\nD)Brisbane\n\nRESPOSTA:";
                cin>>q10;
                if (q10=='C'||q10=='c'){
                    resp++;
                    cout<<"Correto!\n";
                } else {
                    cout<<"Errado! A resposta correta e C) Camberra.\n";
                }
                
                // Exibe o resultado final: ganhou se acertou 5 ou mais questões
                if (resp>=5){
                    cout<<"\n\n\nParabens, voce ganhou!"<<endl<<"Sua nota foi: "<<resp<<endl<<endl<<endl;
                }else{
                    cout<<"\n\n\nVoce perdeu! "<<endl<<"Sua nota foi: "<<resp<<endl<<endl<<endl;
                }
            break;
            
            // Encerra o programa incrementando "game", o que faz o while terminar
            case 3:
                game++;
            break;
            
            // Trata qualquer opção inválida digitada no menu
            default:
                cout<<endl<<endl<<"  | Operacao Invalida!"<<endl<<endl<<endl;
            break;
        }
    }
    return 0;
}
