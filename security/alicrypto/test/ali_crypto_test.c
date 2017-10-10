/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include "ali_crypto.h"
#include "ali_crypto_test.h"

void ali_crypto_test_entry(void)
{
    int ret;

    /* for gcov coverage */
    ali_crypto_print_data("alicrypto TEST", (uint8_t *)"\n", 1);

    ret = ali_crypto_init();
    if (ret < 0) {
        goto _OUT;
    }

    CRYPT_INF("Test hash:\n");
    ret = ali_crypto_hash_test();
    if (ret < 0) {
        goto _OUT;
    }

    CRYPT_INF("Test hmac:\n");
    ret = ali_crypto_hmac_test();
    if (ret < 0) {
        goto _OUT;
    }

    CRYPT_INF("Test rand:\n");
    ret = ali_crypto_rand_test();
    if (ret < 0) {
        goto _OUT;
    }

    CRYPT_INF("Test aes:\n");
    ret = ali_crypto_aes_test();
    if (ret < 0) {
        goto _OUT;
    }

    CRYPT_INF("Test rsa:\n");
    ret = ali_crypto_rsa_test();
    if (ret < 0) {
        goto _OUT;
    }

_OUT:
    ali_crypto_cleanup();
    return;
}

#if 0
int main(void)
{
    ali_crypto_test_entry(NULL);

    return 0;
}
#endif