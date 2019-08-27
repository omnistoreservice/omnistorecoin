// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The OmniStoreCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x00000742ecbd06fbd85a3555ed8656bc36f18ac8650dc2f1f03834513dc42849"))
    (500, uint256("0x05def76cbd20988854f46318d917a44948ff59aa12fbbd10b6d7281e75353868"))
    (1000, uint256("0xe3c633470b6e54fad15b1195ec6ce5813fd6a53bf29c0325df8159a9f9dadf4b"))
    (1500, uint256("0x78f50787beea146b86e70f1f99185ad4e3c0ae68a67a7e91775bb264698420e5"))
    (2000, uint256("0xcd4d4f0cb06eb44a47e020c343b3a5fd32b8f110084ecf0e26733f28f991b0b3"))
    (2500, uint256("0x9a7ed887440ba178080372a7be76bedf810a0e53e089066fb2e442e12f116196"))
    (3000, uint256("0xadc298d860a3e4a872d9e4385c540ccbca105644a9a49b2faaea1474775eea55"))
    (3500, uint256("0xe7179473d05bb0e21ce128ff402c5fe921e14769a7779551203e8ef8f0321f3b"))
    (4000, uint256("0x8c9204302bbd43fe6a6d7c5d3caf367ca9d45146e8e7108701dbb93c2bae50f1"))
    (4500, uint256("0xad32fc69c7a22a6184276cb680c7bedaa4b10bd149fd01d37f0c961b06be2901"))
    (5000, uint256("0x3819b686c7a27c887afd45172b1b4a8a96f6df366b6923cf5c1bfcdc0fc783cd"))
    (5500, uint256("0x31b84fe4eadeca574e997761da21285e65d58e19372f7e86ea0de03629736cf0"))
    (6000, uint256("0x1e61990fe529b01410e2e49c55777318129c2e5befa94d014e66f05615c55805"))
    (6500, uint256("0xfc2822fbaec9204ae95c2ebb5090a21f35ce3c4dc789b24644a8e43152d7b073"))
    (7000, uint256("0xc1e86e22705b7d8a39ed4a912348a236154b7cba6525fa1efe7e141fe56c2e1e"))
    (7500, uint256("0xad233bca65d8aaff893135778f0d179d214adceda976fe05649a6b01e8b619f1"))
    (8000, uint256("0xf41dc11bc38ff968ffad3bbfe7ff9e54c4f1bf27be8dd382d6fe99113c620673"))
    (8500, uint256("0x99f0d8ed146ff269089fb3a64d8e759df07776e22eb983e141d9f347e9d7e915"))
    (9000, uint256("0x9738f72a92bcbba0b02215aeca1c802efd166d8cae76a2a5056e6019560f7315"))
    (9500, uint256("0x9213d3e20faae18c7b0406ef1e9cad9448c30126d6ff8082067825865fbcc63a"))
    (10000, uint256("0x1c4f6c6f8cb869f9b1ec6b2e0f050f0b64eb0077a096c7030e42e02e955ac989"))
    (10500, uint256("0x5227f4840a116dcebf5e67f8bc9510788267e9e8848305e5de6248728a76a411"))
    (11000, uint256("0xc6c3f1a6d282957837fa4646451bbbd5951ef29d6d13bd0d2e65fccea82bf59b"))
    (11500, uint256("0xe9712ec579604286fe27f1862ce02fe208aa26fe5fd01ac4939efcbe0bd5e5bf"))
    (12000, uint256("0xc0555a9747bcc9bb0e1f13e6ff29afcd81430a18f3c71e0a6745fd716359a000"))
    (12500, uint256("0x23fa7aefec9a9d5256b4d2ad9a485543f28be35c001e167bb8571e484d68b2ac"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1563421245, // * UNIX timestamp of last checkpoint block
    24854,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2800        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1551441600,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x1b;
        pchMessageStart[1] = 0xc5;
        pchMessageStart[2] = 0xae;
        pchMessageStart[3] = 0x5b;
        vAlertPubKey = ParseHex("04b590f0fe5a12f294217286e3ce0f5718457a01cad93dc6ad830c06fbb16d52a2968184a68ddca1c85c69d2d41fc99f5000ded51247e0967f132dc09b7c243b9b");
        nDefaultPort = 6854;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // OmniStoreCoin starting difficulty is 1 / 2^12
        //nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // OmniStoreCoin: 1 minute
        nTargetSpacing = 1 * 60;  // OmniStoreCoin: 1 minute
        nMaturity = 15;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 45000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 150;
        nModifierUpdateBlock = 999999999;
        nZerocoinStartHeight = 151;
        nZerocoinStartTime = 1551441600; // Saturday, February 23, 2019 12:00:00 GMT	
        nBlockEnforceSerialRange = 253; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = ~1; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = ~1; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = ~1; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0 * COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 151; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nEnforceNewSporkKey = 1551450600; //!> Sporks signed after (GMT): Saturday, February 23, 2019 15:00:00 GMT must use the new spork key
        nRejectOldSporkKey = 1527811200; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Captain's log, stardate 49146.8. The new USS Enterprise NCC 1701-E is launched.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
		txNew.vout[0].SetEmpty();
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04325f3c3db0d01599a7dd666eec26eb78bd4a4904e3e9ac76e77cce33d9c972a644683449022e70d5f78cc883873995b9942b5a81b748bd050bb4d22f38198f76") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1551441600;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 362118;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000742ecbd06fbd85a3555ed8656bc36f18ac8650dc2f1f03834513dc42849"));
        assert(genesis.hashMerkleRoot == uint256("0x5829a8c42abcd1a9b8b9f28f49b86006d7e8c3ae1897d6b144a5be950862bc96"));

        vSeeds.push_back(CDNSSeedData("0", "84.22.100.200"));     // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("1", "84.22.100.206"));    // Secondary DNS Seeder
        vSeeds.push_back(CDNSSeedData("2", "37.252.120.92"));
        /*vSeeds.push_back(CDNSSeedData("3", "84.22.98.63"));
        vSeeds.push_back(CDNSSeedData("4", "46.19.34.23"));
        vSeeds.push_back(CDNSSeedData("5", "46.19.34.17"));
        vSeeds.push_back(CDNSSeedData("6", "46.19.34.47"));
        vSeeds.push_back(CDNSSeedData("7", "84.22.97.15"));*/
        
        // OmniStoreCoin addresses start with 'B'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 25);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 25);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        // OmniStoreCoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // OmniStoreCoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x05).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));    
        
        fMiningRequiresPeers = true;               //true
        fAllowMinDifficultyBlocks = true;          //false
        fDefaultConsistencyChecks = false;          //false
        fRequireStandard = true;                    //true
        fMineBlocksOnDemand = false;                //false
        fSkipProofOfWorkCheck = true;              //false
        fTestnetToBeDeprecatedFieldRPC = false;     //false
        fHeadersFirstSyncingActive = false;         //false

        nPoolMaxTransactions = 3;
        strSporkKey = "04bd06b0a08f250f845746c333721541318735d1c2e5e2b716396e1b8d9b111370e2d5a75fbabe43ea128f2e1323efccdeda060d69839a95a62919f99fb5011d4a";
        strSporkKeyOld = "04bd06b0a08f250f845746c333721541318735d1c2e5e2b716396e1b8d9b111370e2d5a75fbabe43ea128f2e1323efccdeda060d69839a95a62919f99fb5011d4a";
        strObfuscationPoolDummyAddress = "BAM7N3gH9vFQmAC6PgQTB2r4LD1MrMM9jD";
        nStartMasternodePayments = 1551441600; //Saturday, February 23, 2019 12:00:00 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zomns to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x25;
        pchMessageStart[1] = 0x68;
        pchMessageStart[2] = 0x46;
        pchMessageStart[3] = 0xab;
        vAlertPubKey = ParseHex("04868fc0756b3a7f2a43c00261864c76982272a59db0d2bd067a27bf13488044b8e1a41dc62a13f1c4bf2fdf6ee1680100dd631dd7b3fe8207789125c04a19cca2");
        nDefaultPort = 6856;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // OmniStoreCoin: 1 minute
        nTargetSpacing = 1 * 60;  // OmniStoreCoin: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        nZerocoinStartTime = 1501776000;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1551441600;
        genesis.nNonce = 2402015;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "omnistorecoin-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "omnistorecoin-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 85); // Testnet omnistorecoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 85);  // Testnet omnistorecoin script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet omnistorecoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // Testnet omnistorecoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // Testnet omnistorecoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "0470dcc2443a0e5834a379edb92e563e121a79eea6849ca065d322a01ea153c50aa52e213bab1df36840de095c5d10475272314c5a226e7b34b02ff15f681014ac";
        strSporkKeyOld = "046d00079ea2e1e20f8a0edb5447d701badf6bc086038c5d5c5f6a0ee5428969635682f458cd5091940012334faa8509e8f7dee6a7afdb1f48379ec16cddc145ce";
        strObfuscationPoolDummyAddress = "bKGceQJGFqyTzpjB7CCVUJ25ae6xwNrZBr";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xb3;
        pchMessageStart[1] = 0xac;
        pchMessageStart[2] = 0xcf;
        pchMessageStart[3] = 0x5a;
        //nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // OmniStoreCoin: 1 day
        nTargetSpacing = 1 * 60;        // OmniStoreCoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1551441600;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 6858;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 6859;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    //virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
