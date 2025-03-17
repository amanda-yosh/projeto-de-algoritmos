#include <stdio.h>
#include <string.h>

char* noTimeToCode(
    int numberOfMattersCDFCanResolve,
    char v[][100],
    int* daysToResolveV,
    int daysToResolve, 
    char* matterAskedByTheProfessor
) {
    for (int i = 0; i < numberOfMattersCDFCanResolve; i++) {
        if (strcmp(v[i], matterAskedByTheProfessor) == 0) {
            int totalDaysToSubmit = 5 + daysToResolve;

            if (daysToResolveV[i] <= daysToResolve) {
                return "Ufa!";
            }

            if (daysToResolveV[i] > daysToResolve && daysToResolveV[i] <= totalDaysToSubmit) {
                return "Atrasado";
            }
            
            if (daysToResolveV[i] > totalDaysToSubmit) {
                return "Deu ruim! Va trabalhar";
            }
        }        
    }

    return "Deu ruim! Va trabalhar";
}

int main() {
    int numberOfTestCases;
    scanf("%d", &numberOfTestCases);

    char result[numberOfTestCases][100];

    for (int i = 0; i < numberOfTestCases; i++) {
        int numberOfMattersCDFCanResolve;
        scanf("%d", &numberOfMattersCDFCanResolve);

        char v[numberOfMattersCDFCanResolve][100];
        int daysToResolveV[numberOfMattersCDFCanResolve];
        for (int i = 0; i < numberOfMattersCDFCanResolve; i++) {
            scanf(" %s %d", v[i], &daysToResolveV[i]);
        }

        int daysToResolve;
        scanf("%d", &daysToResolve);

        char matterAskedByTheProfessor[100];
        scanf(" %s", matterAskedByTheProfessor);

        strcpy(result[i], noTimeToCode(numberOfMattersCDFCanResolve, v, daysToResolveV, daysToResolve, matterAskedByTheProfessor));
    }

    for(int i = 0; i < numberOfTestCases; i++) {
        printf("Case %d: %s\n", i+1, result[i]);
    }

    return 0;
}
