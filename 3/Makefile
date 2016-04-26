KEY = '1234567812345678'
INPUT = 'sample/text'

ENCRYPTED_OUTPUT = 'sample/encrypted'
DECRYPTED_OUTPUT = 'sample/decrypted'

TEST_COUNT = 30
TEST_LENGTH = 1000000


build: tea.c
	@gcc -std=c99 -o tea tea.c

run: build
	@./tea encrypt $(KEY) $(INPUT) $(ENCRYPTED_OUTPUT)
	@./tea decrypt $(KEY) $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT)
	@cmp -l $(INPUT) $(DECRYPTED_OUTPUT)

genkey: tea.c
	@gcc -std=c99 -o tea tea.c
	@./tea generate_key

gentests: testgen.c
	@mkdir -p tests
	@gcc -std=c99 -o testgen testgen.c
	@./testgen $(TEST_COUNT) $(TEST_LENGTH)

test: build test.sh
	@./test.sh

clean:
	@rm -rf $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT)
	@rm -rf tea testgen a.out
	@rm -rf tests/*.test
