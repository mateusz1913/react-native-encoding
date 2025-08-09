import { Buffer } from 'buffer';
import type { ReactNativeEncodingModule } from './types';

const base64DecodingTable = [
  99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 0 - 15 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
  99, 99, 99, 99, 99, 99 /* 16 - 31 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 62, 99, 99, 99, 63 /* 32 - 47 */,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 99, 99, 99, 64, 99, 99 /* 48 - 63 */, 99, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14 /* 64 - 79 */, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 99, 99, 99, 99, 99 /* 80 - 95 */, 99, 26,
  27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 /* 96 - 111 */, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 99,
  99, 99, 99, 99 /* 112 - 127 */,
];
function decodeFromBase64BufferToUtf8String(base64Str: string): string {
  const pad = base64Str[base64Str.length - 1] == '=';
  let offset;

  if (pad) {
    offset = (Math.floor(base64Str.length / 4) - 1) * 4;
  } else {
    offset = Math.floor(base64Str.length / 4) * 4;
  }

  const isPad1 = base64Str[offset + 2] != '=';

  let decodedStr = '';

  for (let i = 0; i < offset; i += 4) {
    const b1 = base64DecodingTable[base64Str.charCodeAt(i)];
    const b2 = base64DecodingTable[base64Str.charCodeAt(i + 1)];
    const b3 = base64DecodingTable[base64Str.charCodeAt(i + 2)];
    const b4 = base64DecodingTable[base64Str.charCodeAt(i + 3)];

    const quartet = (b1 << 18) | (b2 << 12) | (b3 << 6) | b4;

    decodedStr += String.fromCharCode(quartet >> 16);
    decodedStr += String.fromCharCode((quartet >> 8) & 0xff);
    decodedStr += String.fromCharCode(quartet & 0xff);
  }

  if (pad) {
    const b1 = base64DecodingTable[base64Str.charCodeAt(offset)];
    const b2 = base64DecodingTable[base64Str.charCodeAt(offset + 1)];

    const quartet = (b1 << 18) | (b2 << 12);

    decodedStr += String.fromCharCode(quartet >> 16);

    if (isPad1) {
      const b3 = base64DecodingTable[base64Str.charCodeAt(offset + 2)];

      decodedStr += String.fromCharCode(((quartet | (b3 << 6)) >> 8) & 0xff);
    }
  }

  return decodedStr;
}

const base64EncodingTable = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
function encodeFromUtf8BufferToBase64String(utf8Str: string): string {
  const pad = utf8Str.length % 3;
  const last = utf8Str.length - pad;

  const encodedStrSize = Math.floor((utf8Str.length + 2) / 3) * 4;
  const encodedStr = Array.from({ length: encodedStrSize }, () => '=');

  let i = 0;
  for (let j = 0; j < last; j += 3) {
    const triple = (utf8Str.charCodeAt(j) << 16) | (utf8Str.charCodeAt(j + 1) << 8) | utf8Str.charCodeAt(j + 2);

    encodedStr[i++] = base64EncodingTable[triple >> 18];
    encodedStr[i++] = base64EncodingTable[(triple >> 12) & 0x3f];
    encodedStr[i++] = base64EncodingTable[(triple >> 6) & 0x3f];
    encodedStr[i++] = base64EncodingTable[triple & 0x3f];
  }

  if (pad) {
    if (pad == 1) {
      const triple = utf8Str.charCodeAt(last);

      encodedStr[i++] = base64EncodingTable[triple >> 2];
      encodedStr[i++] = base64EncodingTable[(triple << 4) & 0x3f];
    } else if (pad == 2) {
      const triple = (utf8Str.charCodeAt(last) << 8) | utf8Str.charCodeAt(last + 1);

      encodedStr[i++] = base64EncodingTable[triple >> 10];
      encodedStr[i++] = base64EncodingTable[(triple >> 4) & 0x3f];
      encodedStr[i++] = base64EncodingTable[(triple << 2) & 0x3f];
    }
  }

  return encodedStr.join('');
}

const hexDecodingTable = [
  99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 0 - 15 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
  99, 99, 99, 99, 99, 99 /* 16 - 31 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 32 - 47 */, 0,
  1, 2, 3, 4, 5, 6, 7, 8, 9, 99, 99, 99, 99, 99, 99 /* 48 - 63 */, 99, 10, 11, 12, 13, 14, 15, 99, 99, 99, 99, 99, 99,
  99, 99, 99 /* 64 - 79 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 80 - 95 */, 99, 16, 17,
  18, 19, 20, 21, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 96 - 111 */, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
  99, 99, 99 /* 112 - 127 */,
];
function decodeFromHexStringToUTF8String(hexStr: string): string {
  let utf8Str = '';
  for (let i = 0; i < hexStr.length; i += 2) {
    const b1 = hexDecodingTable[hexStr.charCodeAt(i)];
    const b2 = hexDecodingTable[hexStr.charCodeAt(i + 1)];
    const charCode = (b1 << 4) | b2;

    utf8Str += String.fromCharCode(charCode);
  }

  return utf8Str;
}

const hexDictionary = '0123456789ABCDEFabcdef';
function encodeFromUTF8StringToHexString(utf8Str: string): string {
  let hexStr = '';
  for (let i = 0; i < utf8Str.length; i++) {
    hexStr += hexDictionary[(utf8Str.charCodeAt(i) & 0xf0) >> 4];
    hexStr += hexDictionary[utf8Str.charCodeAt(i) & 0x0f];
  }

  return hexStr;
}

export const ReactNativeEncoding: ReactNativeEncodingModule = {
  convertFromArrayBufferToBase64: (arrayBuffer) => {
    return Buffer.from(arrayBuffer).toString('base64');
  },
  convertFromArrayBufferToHex: (arrayBuffer) => {
    return Buffer.from(arrayBuffer).toString('hex');
  },
  convertFromArrayBufferToUTF8: (arrayBuffer) => {
    return Buffer.from(arrayBuffer).toString('utf8');
  },
  convertFromBase64ToArrayBuffer: (base64Str) => {
    return Buffer.from(decodeFromBase64BufferToUtf8String(base64Str));
  },
  convertFromBase64ToHex: (base64Str) => {
    return encodeFromUTF8StringToHexString(decodeFromBase64BufferToUtf8String(base64Str));
  },
  convertFromBase64ToUTF8: (base64Str) => {
    return decodeFromBase64BufferToUtf8String(base64Str);
  },
  convertFromHexToArrayBuffer: (hexStr) => {
    return Buffer.from(decodeFromHexStringToUTF8String(hexStr));
  },
  convertFromHexToBase64: (hexStr) => {
    return encodeFromUtf8BufferToBase64String(decodeFromHexStringToUTF8String(hexStr));
  },
  convertFromHexToUTF8: (hexStr) => {
    return decodeFromHexStringToUTF8String(hexStr);
  },
  convertFromUTF8ToArrayBuffer: (utf8Str) => {
    return Buffer.from(utf8Str);
  },
  convertFromUTF8ToBase64: (utf8Str) => {
    return encodeFromUtf8BufferToBase64String(utf8Str);
  },
  convertFromUTF8ToHex: (utf8Str) => {
    return encodeFromUTF8StringToHexString(utf8Str);
  },
};
