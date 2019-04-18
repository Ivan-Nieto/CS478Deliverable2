all:
	g++ project2_encryption.cpp -L/usr/local/ssl/lib -lssl -lcrypto
	./a.out symm_key.bin pubkey.pem private.pem
	g++ project2_decryption.cpp
	./a.out sec.signed.base64.enc public.pem symmetric.txt
