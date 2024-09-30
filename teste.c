#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{ // main ponto de partida
  // int é uma variavel da linguagem c do tipo inteiro
    printf("            Bem vindo de Jogo de Adivinhacao          \n");
    printf("            __..--''``---....___   _..._    __          \n");
    printf("   /// //_.-'    .-/" "  `        ``<._  ``.''_ `. / // /\n");
    printf("  ///_.-' _..--.'_    \                    `( ) ) // // \n");
    printf("  / (_..-' // (< _     ;_..__               ; `' / ///  \n");
    printf("   / // // //  `-._,_)' // / ``--...____..-' /// / //  \n");
    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecret = numerogrande % 100;

    int chute;
    int tentativas = 1; // int numeros inteiros, então quando tiver virgula ele ignora a virgula

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;
    case 2:
        numerodetentativas = 15;
        break;
    default:
        numerodetentativas = 6;
        break;
    }

    // double pi = 3.1415; pode fazer operações com casas decimais, com virgula

    // for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++)
    // while(1) { while enquanto
    for (int i = 1; i <= numerodetentativas; i++)
    {

        printf("Tentativa %d \n", tentativas);
        printf("Qual e o seu chute? ");

        scanf("%d", &chute); // %d só recebe numero inteiro, passa a variavel também
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!\n");

            continue;
            ;
        }

        acertou = (chute == numerosecret); // == é uma comparaçao
        int maior = chute > numerosecret;

        if (acertou)
        {
            printf("Parabens voce acertou!\n");
            printf("Jogue novamente, voce eh um bom jogador!\n");

            break; // Para o loop
        }

        else if (maior)
        {
            printf("Seu chute foi maior que o numero secreto\n");
        }

        else
        {
            printf("Seu chute foi menor que o numero secreto\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecret) / 2.0; // só de coloca o 2.0 é um double, esse abs converte o numero negativo para positivio
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de jogo! \n");

    if (acertou)
    {
        printf("     ,-. __ .-,    \n");
        printf("  --;`. '   `.'    \n");
        printf("   / (  ^__^  )    \n");
        printf("  ;   `(_`'_)' \   \n");
        printf("  '  ` .`--'_,  ;  \n");
        printf(" ~~`-..._)))(((.'  \n");
        printf("Voce ganhou!\n");
        printf("Voce acertou em %d tentativas!", tentativas);
        printf("Total de pontos: %.1f\n", pontos); // mascara do inteiro é f e de int é d //da paraalternar o nnumero da casas decimais com .1
    }
    else
    {
        printf("Voce perdeu! Tente de novo\n");

        printf("          |\      _,,,---,,_              \n");
        printf("   ZZZzz /,`.-'`'    -.  ;-;;,_           \n");
        printf("        |,4-  ) )-,_. ,\ (  `'-'          \n");
        printf("       '---''(_/--'  `-'\_)               \n");
    }
}
