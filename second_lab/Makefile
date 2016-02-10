KEY = '1234567812345678'
INPUT = 'text'
ENCRYPTED_OUTPUT = 'encrypted'
DECRYPTED_OUTPUT = 'decrypted'

run: tea.c
	@gcc -std=c99 -o tea tea.c
	@./tea encrypt $(KEY) $(INPUT) $(ENCRYPTED_OUTPUT)
	@./tea decrypt $(KEY) $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT)
	@diff -B -d -y $(INPUT) $(INPUT)
clean:
	@rm -f $(ENCRYPTED_OUTPUT) $(DECRYPTED_OUTPUT) tea
