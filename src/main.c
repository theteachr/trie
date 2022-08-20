#include <stdio.h>
#include "trie.h"

int main(void)
{
	char *zip_code_data[] = {
		"781109",
		"560782",
		"789663"
	};

	struct Trie zip_codes;

	init_trie(&zip_codes);

	for (int i = 0; i < 3; i++)
		insert(&zip_codes, zip_code_data[i]);

	print_trie(&zip_codes);

	char* key = "560782";

	printf("%s was%sfound.\n", key, search(&zip_codes, key) ? " " : " not ");

	return 0;
}
