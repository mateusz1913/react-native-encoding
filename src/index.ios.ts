import NativeReactNativeEncodingModule from './specs/NativeReactNativeEncodingModule';
import type { ReactNativeEncodingModule } from './types';

export const ReactNativeEncoding: ReactNativeEncodingModule = {
  convertFromArrayBufferToBase64: (arrayBuffer) => {
    return NativeReactNativeEncodingModule.convertFromArrayBufferToBase64(arrayBuffer.buffer);
  },
  convertFromArrayBufferToHex: (arrayBuffer) => {
    return NativeReactNativeEncodingModule.convertFromArrayBufferToHex(arrayBuffer.buffer);
  },
  convertFromArrayBufferToUTF8: (arrayBuffer) => {
    return NativeReactNativeEncodingModule.convertFromArrayBufferToUTF8(arrayBuffer.buffer);
  },
  convertFromBase64ToArrayBuffer: (base64Str) => {
    return new Uint8Array(NativeReactNativeEncodingModule.convertFromBase64ToArrayBuffer(base64Str) as ArrayBuffer);
  },
  convertFromBase64ToHex: (base64Str) => {
    return NativeReactNativeEncodingModule.convertFromBase64ToHex(base64Str);
  },
  convertFromBase64ToUTF8: (base64Str) => {
    return NativeReactNativeEncodingModule.convertFromBase64ToUTF8(base64Str);
  },
  convertFromHexToArrayBuffer: (hexStr) => {
    return new Uint8Array(NativeReactNativeEncodingModule.convertFromHexToArrayBuffer(hexStr) as ArrayBuffer);
  },
  convertFromHexToBase64: (hexStr) => {
    return NativeReactNativeEncodingModule.convertFromHexToBase64(hexStr);
  },
  convertFromHexToUTF8: (hexStr) => {
    return NativeReactNativeEncodingModule.convertFromHexToUTF8(hexStr);
  },
  convertFromUTF8ToArrayBuffer: (utf8Str) => {
    return new Uint8Array(NativeReactNativeEncodingModule.convertFromUTF8ToArrayBuffer(utf8Str) as ArrayBuffer);
  },
  convertFromUTF8ToBase64: (utf8Str) => {
    return NativeReactNativeEncodingModule.convertFromUTF8ToBase64(utf8Str);
  },
  convertFromUTF8ToHex: (utf8Str) => {
    return NativeReactNativeEncodingModule.convertFromUTF8ToHex(utf8Str);
  },
};
