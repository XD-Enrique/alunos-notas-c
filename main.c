#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float calcularMedia(float notas[], int qtd);

int main()
{
    char nomes[50][100];   
    int qtd_alunos, i;
    int idades[50];
    float notas[50];

    do {
        printf("\nInsira a quantidade de alunos (max 50): \n");
        scanf ("%i", &qtd_alunos);
        if (qtd_alunos > 50 || qtd_alunos <= 0) {
            system("clear");
            printf("\nQuantidade inválida! Por favor, digite um número entre 1 e 50.\n");
        }

    } while (qtd_alunos > 50 || qtd_alunos <= 0);

    for (i=0; i<qtd_alunos; i++) {
        getchar();

        printf("\nInsira o nome do(a) aluno(a) %d: \n", i+1);
        fgets(nomes[i], sizeof(nomes[i]), stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("\nInsira a idade do(a) aluno(a) %d: \n", i+1);
        scanf("%i", &idades[i]);

        printf("\nInsira a nota do(a) aluno(a) %d: \n", i+1);
        scanf("%f", &notas[i]);

    }
    system("clear");

    float media=calcularMedia(notas, qtd_alunos);

    int aprovados=0;
    int indiceMaiorNota=0;

    for (int i=0; i<qtd_alunos; i++) {
        if (notas[i]>=6.0)
            aprovados++;

        if (notas[i]>notas[indiceMaiorNota])
            indiceMaiorNota=i;
    }

    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Mostrar todos os alunos\n");
        printf("2. Mostrar apenas aprovados (nota >= 6.0)\n");
        printf("3. Mostrar apenas reprovados (nota < 6.0)\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao){
            case 1:
            printf("\nTODOS OS ALUNOS:\n");
            for (int i=0; i<qtd_alunos; i++) {
                printf("%s - Idade: %d - Nota: %.2f -", nomes[i], idades[i], notas[i]);
                if (notas[i]>=6.0)
                    printf("APROVADO\n");
                else
                    printf("REPROVADO\n");
            }
            break;

            case 2:
                printf("\nALUNOS APROVADOS:\n");
                    for (int i = 0; i < qtd_alunos; i++) {
                        if (notas[i] >= 6.0)
                            printf("%s - Idade: %d - Nota: %.2f -\n", nomes[i], idades[i], notas[i]);
            }
            break;

            case 3:
                printf("\nALUNOS REPROVADOS:\n");
                    for (int i = 0; i < qtd_alunos; i++) {
                        if (notas[i] < 6.0)
                        printf("%s - Idade: %d - Nota: %.2f -\n", nomes[i], idades[i], notas[i]);
                    }
            break;

            case 4:
            printf("Encerrando programa...\n");
            break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    printf("\n--- RESUMO GERAL ---\n");
    printf("Média da turma: %.2f\n", media);
    printf("Maior nota: %.2f - Aluno: %s\n", notas[indiceMaiorNota], nomes[indiceMaiorNota]);

    return 0;
}

float calcularMedia(float notas[], int qtd){
    float soma = 0;
    for (int i=0; i<qtd; i++) {
        soma+=notas[i];
    }
    return soma/qtd;
}
