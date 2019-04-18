all:
	g++ project2_encryption.cpp
	./a.out symm_key.bin pubkey.pem myprivate.pem
	g++ project2_decryption.cpp
	./a.out sec.signed.base64.enc mypublic.pem symmetric.txt sec.enc
