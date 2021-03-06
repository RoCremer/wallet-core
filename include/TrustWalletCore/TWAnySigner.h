// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#pragma once

#include "TWBase.h"
#include "TWCoinType.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

/// Helper class to sign any transactions.
struct TWAnySigner;

/// Signs a transaction.
extern TWData *_Nonnull TWAnySignerSign(TWData *_Nonnull input, enum TWCoinType coin);

/// Signs a json transaction with private key.
extern TWString *_Nonnull TWAnySignerSignJSON(TWString *_Nonnull json, TWData *_Nonnull key, enum TWCoinType coin);

extern bool TWAnySignerSupportsJSON(enum TWCoinType coin);

/// Encodes serialized SigningInput data to raw platform/coin specific bytes
/// Example: EthereumSigningInput will be encoded as raw RLP bytes which can be sent over JSONRPC (eth_sendRawTransaction)
extern TWData *_Nonnull TWAnySignerEncode(TWData *_Nonnull input, enum TWCoinType coin);

/// Decodes raw platform/coin specific bytes to representable json data
/// Example: Ethereum RLP bytes will be decoded into same json returned from JSONRPC (eth_getTransactionByHash)
extern TWData *_Nonnull TWAnySignerDecode(TWData *_Nonnull input, enum TWCoinType coin);

/// Plan a transaction (for UTXO chains).
extern TWData *_Nonnull TWAnySignerPlan(TWData *_Nonnull input, enum TWCoinType coin);

TW_EXTERN_C_END
