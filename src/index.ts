import { Buffer } from 'buffer';
import type { ReactNativeEncodingModule } from './types';

export const ReactNativeEncoding: ReactNativeEncodingModule = {
  convertFromArrayBufferToBase64: (arrayBuffer) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(arrayBuffer).toString('base64');
  },
  convertFromArrayBufferToHex: (arrayBuffer) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(arrayBuffer).toString('hex');
  },
  convertFromArrayBufferToUTF8: (arrayBuffer) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(arrayBuffer).toString('utf8');
  },
  convertFromBase64ToArrayBuffer: (base64Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(base64Str, 'base64');
  },
  convertFromBase64ToHex: (base64Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(base64Str, 'base64').toString('hex');
  },
  convertFromBase64ToUTF8: (base64Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(base64Str, 'base64').toString('utf8');
  },
  convertFromHexToArrayBuffer: (hexStr) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(hexStr, 'hex');
  },
  convertFromHexToBase64: (hexStr) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(hexStr, 'hex').toString('base64');
  },
  convertFromHexToUTF8: (hexStr) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(hexStr, 'hex').toString('utf8');
  },
  convertFromUTF8ToArrayBuffer: (utf8Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(utf8Str, 'utf8');
  },
  convertFromUTF8ToBase64: (utf8Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(utf8Str, 'utf8').toString('base64');
  },
  convertFromUTF8ToHex: (utf8Str) => {
    if (typeof Buffer === 'undefined') {
      throw new Error(
        'react-native-encoding uses Buffer npm package for Web compatibility and seems it is not installed. Please run `npm install buffer`',
      );
    }
    return Buffer.from(utf8Str, 'utf8').toString('hex');
  },
};
