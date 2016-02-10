KEY = '1234567812345678'
INPUT = 'sample/text'
ENCRYPTED_OUTPUT = 'sample/encrypted'
DECRYPTED_OUTPUT = 'sample/decrypted'

run: tea.c
	@gcc -std=c99 -o tea tea.c
	@./tea encrypt $(KEY) $(INPUT) $(ENCRYPTED_OUTPUT)
	@./tea decrypt $(KEY) $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT)
	@cmp -l $(INPUT) $(DECRYPTED_OUTPUT)
clean:
	@rm -f $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT) tea
