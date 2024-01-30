/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:16:12 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/24 17:17:50 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction de comparaison pour la fonction qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Aucun argument fourni.\n");
        return 1;
    }

    // Trier les arguments (à partir de argv[1])
    qsort(&argv[1], argc - 1, sizeof(char *), compare);

    // Afficher les arguments triés
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}

