/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:01:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 16:04:02 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_test(char *input)
{
    t_token *tokens;
    t_token *tmp;
    int     i = 0;

    printf("\033[1;34mTesting: \033[0m[%s]\n", input);
    printf("--------------------------------------\n");
    
    // Assuming your lexer takes (NULL/ptr, string)
    tokens = lexer(0, input); 
    
    tmp = tokens;
    while (tmp)
    {
        printf("Token %d: type=%d | value='%s'\n", i++, tmp->type, tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    // Add your list freeing function here to avoid leaks!
    // free_lexer(tokens); 
}

int main(void)
{
    char *tests[] = {
        /* 1. Basic Operators */
        "ls -la | grep .c",
        "ls>fileout>>append<filein",
        
        /* 2. Complex Quotes (The "hel"lo case) */
        "\"hel\"lo",                // Should be 1 token: hello
        "echo \"  spaced  \"",      // Should be 2 tokens: echo |   spaced  
        "''\"\"' '",                // Should be 1 token: (space)
        "ls' -la'",                 // Should be 1 token: ls -la
        
        /* 3. Metacharacters inside quotes */
        "echo \"| >> <\"",          // Should be 2 tokens: echo | | >> <
        "grep '|' file",            // Should be 3 tokens: grep | | | file
        
        /* 4. Environment Variables (Lexer shouldn't expand, just keep as WORD) */
        "echo $USER",
        "echo \"$USER\"",
        "echo '$USER'",             // Difference is handled in expansion, not lexer
        
        /* 5. Edge cases / Syntax errors */
        "|||",                      // 3 PIPE tokens
        ">>>",                      // REDIR_APPEND + REDIR_OUT (or syntax error later)
        "   ",                      // Should return NULL or empty
        "\"unclosed quote",         // Your choice: error or literal
        NULL
    };

    for (int i = 0; tests[i]; i++)
        run_test(tests[i]);

    return (0);
}
