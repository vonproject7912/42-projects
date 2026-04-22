/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:04:30 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 16:12:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell.h"

/* ========================================================================== */
/* MOCKING TOOLS                                 */
/* ========================================================================== */

// Helper to quickly build fake lexer output
void mock_token(t_token **tokens, t_type type, char *value)
{
	t_token *new = new_token();
	new->type = type;
	if (value)
		new->value = ft_strndup(value, ft_strlen(value)); // Using your util
	add_token(tokens, new);
}

// Helper to print the final command structures
void print_commands(t_cmd *cmds)
{
	t_cmd	*cur_cmd = cmds;
	int		cmd_idx = 0;

	if (!cmds)
	{
		printf("  [!] No commands generated (or syntax error).\n");
		return ;
	}
	while (cur_cmd)
	{
		printf("  --- Command %d ---\n", cmd_idx++);
		
		// 1. Print Arguments
		printf("  Argv: [");
		for (int i = 0; cur_cmd->argv && cur_cmd->argv[i]; i++)
		{
			printf("\"%s\"", cur_cmd->argv[i]);
			if (cur_cmd->argv[i + 1])
				printf(", ");
		}
		printf("]\n");

		// 2. Print Redirections
		t_redir *cur_redir = cur_cmd->redirs;
		if (cur_redir)
			printf("  Redirections:\n");
		else
			printf("  Redirections: None\n");
		
		while (cur_redir)
		{
			char *type_str = "UNKNOWN";
			if (cur_redir->type == REDIR_IN) type_str = "< (IN)";
			if (cur_redir->type == REDIR_OUT) type_str = "> (OUT)";
			if (cur_redir->type == REDIR_APPEND) type_str = ">> (APPEND)";
			if (cur_redir->type == HEREDOC) type_str = "<< (HEREDOC)";

			printf("    -> %s '%s'\n", type_str, cur_redir->file ? cur_redir->file : "NULL");
			cur_redir = cur_redir->next;
		}
		cur_cmd = cur_cmd->next;
	}
}

/* ========================================================================== */
/* TEST ROUTINE                                 */
/* ========================================================================== */

void run_parser_test(char *test_name, t_token *tokens)
{
	t_cmd	*commands = NULL;
	t_token	*tokens_head = tokens; // Save head to free later
	int		lst_ext = 0; // Mock exit status

	printf("\n\033[1;34mTesting:\033[0m [%s]\n", test_name);
	printf("--------------------------------------\n");

	// 1. Run your syntax check
	if (syntax_check(tokens) == 1)
	{
		// Note: pipe_err() or redir_err() will print to stderr automatically
		printf("  [!] Syntax check failed (Caught expected error).\n");
	}
	else
	{
		// 2. Run your parser
		// Note: append_cmd advances the token pointer, so we pass a copy of the head
		t_token *current_token = tokens; 
		commands = append_cmd(&lst_ext, &current_token, commands);
		
		// 3. Print results
		print_commands(commands);
	}

	// 4. Clean up using your functions
	free_commands(&commands);
	free_tokens(&tokens_head); 
}

/* ========================================================================== */
/* MAIN                                      */
/* ========================================================================== */

int main(void)
{
	t_token *tokens = NULL;

	/* Test 1: Simple Command -> "ls -la" */
	tokens = NULL;
	mock_token(&tokens, WORD, "ls");
	mock_token(&tokens, WORD, "-la");
	run_parser_test("Simple Command: ls -la", tokens);

	/* Test 2: Single Pipe -> "ls -la | wc -l" */
	tokens = NULL;
	mock_token(&tokens, WORD, "ls");
	mock_token(&tokens, WORD, "-la");
	mock_token(&tokens, PIPE, NULL);
	mock_token(&tokens, WORD, "wc");
	mock_token(&tokens, WORD, "-l");
	run_parser_test("Pipes: ls -la | wc -l", tokens);

	/* Test 3: Redirections -> "cat < infile > outfile" */
	tokens = NULL;
	mock_token(&tokens, WORD, "cat");
	mock_token(&tokens, REDIR_IN, NULL);
	mock_token(&tokens, WORD, "infile");
	mock_token(&tokens, REDIR_OUT, NULL);
	mock_token(&tokens, WORD, "outfile");
	run_parser_test("Redirections: cat < infile > outfile", tokens);

	/* Test 4: Mixed everything -> "grep pattern < in.txt | wc -l >> append.txt" */
	tokens = NULL;
	mock_token(&tokens, WORD, "grep");
	mock_token(&tokens, WORD, "pattern");
	mock_token(&tokens, REDIR_IN, NULL);
	mock_token(&tokens, WORD, "in.txt");
	mock_token(&tokens, PIPE, NULL);
	mock_token(&tokens, WORD, "wc");
	mock_token(&tokens, WORD, "-l");
	mock_token(&tokens, REDIR_APPEND, NULL);
	mock_token(&tokens, WORD, "append.txt");
	run_parser_test("Mixed: grep pattern < in.txt | wc -l >> append.txt", tokens);

	/* Test 5: Syntax Error -> "ls | | wc" */
	tokens = NULL;
	mock_token(&tokens, WORD, "ls");
	mock_token(&tokens, PIPE, NULL);
	mock_token(&tokens, PIPE, NULL);
	mock_token(&tokens, WORD, "wc");
	run_parser_test("Syntax Error: ls | | wc", tokens);

	/* Test 6: Syntax Error -> ">" (Newline error) */
	tokens = NULL;
	mock_token(&tokens, REDIR_OUT, NULL);
	run_parser_test("Syntax Error: > (nothing after)", tokens);

	return (0);
}
