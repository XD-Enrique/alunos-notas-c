#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
    char nome[100];
    int idade;
    float nota;
} Aluno;

void limparTela();
void cadastrarAlunos(Aluno alunos[], int *qtd);
void mostrarAlunos(Aluno alunos[], int qtd);
void mostrarAprovados(Aluno alunos[], int qtd);
void mostrarReprovados(Aluno alunos[], int qtd);
float calcularMedia(Aluno alunos[], int qtd);
int indiceMaiorNota(Aluno alunos[], int qtd);

int main() {
    Aluno alunos[MAX_ALUNOS];
    int qtd_alunos;
    int opcao;

    do {
        printf("\nInsira a quantidade de alunos (1 a %d): ", MAX_ALUNOS);
        scanf("%d", &qtd_alunos);
        if (qtd_alunos <= 0 || qtd_alunos > MAX_ALUNOS) {
            limparTela();
            printf("⚠️  Quantidade inválida! Tente novamente.\n");
        }
    } while (qtd_alunos <= 0 || qtd_alunos > MAX_ALUNOS);

    cadastrarAlunos(alunos, &qtd_alunos);
    limparTela();

    float media = calcularMedia(alunos, qtd_alunos);
    int maior = indiceMaiorNota(alunos, qtd_alunos);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Mostrar todos os alunos\n");
        printf("2. Mostrar apenas aprovados\n");
        printf("3. Mostrar apenas reprovados\n");
        printf("4. Mostrar resumo geral\n");
        printf("5. Sair\n");
        printf("================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1:
                mostrarAlunos(alunos, qtd_alunos);
                break;
            case 2:
                mostrarAprovados(alunos, qtd_alunos);
                break;
            case 3:
                mostrarReprovados(alunos, qtd_alunos);
                break;
            case 4:
                printf("\n--- RESUMO GERAL ---\n");
                printf("Média da turma: %.2f\n", media);
                printf("Maior nota: %.2f - Aluno: %s\n",
                       alunos[maior].nota, alunos[maior].nome);
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void cadastrarAlunos(Aluno alunos[], int *qtd) {
    for (int i = 0; i < *qtd; i++) {
        getchar(); // limpa buffer
        printf("\nNome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
}

void mostrarAlunos(Aluno alunos[], int qtd) {
    printf("\n--- TODOS OS ALUNOS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%s | Idade: %d | Nota: %.2f | %s\n",
               alunos[i].nome, alunos[i].idade, alunos[i].nota,
               alunos[i].nota >= 6.0 ? "APROVADO" : "REPROVADO");
    }
}

void mostrarAprovados(Aluno alunos[], int qtd) {
    printf("\n--- APROVADOS ---\n");
    for (int i = 0; i < qtd; i++)
        if (alunos[i].nota >= 6.0)
            printf("%s | Idade: %d | Nota: %.2f\n",
                   alunos[i].nome, alunos[i].idade, alunos[i].nota);
}

void mostrarReprovados(Aluno alunos[], int qtd) {
    printf("\n--- REPROVADOS ---\n");
    for (int i = 0; i < qtd; i++)
        if (alunos[i].nota < 6.0)
            printf("%s | Idade: %d | Nota: %.2f\n",
                   alunos[i].nome, alunos[i].idade, alunos[i].nota);
}

float calcularMedia(Aluno alunos[], int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++)
        soma += alunos[i].nota;
    return soma / qtd;
}

int indiceMaiorNota(Aluno alunos[], int qtd) {
    int indice = 0;
    for (int i = 1; i < qtd; i++)
        if (alunos[i].nota > alunos[indice].nota)
            indice = i;
    return indice;
}
