export interface ReactNativeEncodingModule {
  convertFromArrayBufferToBase64: (arrayBuffer: Uint8Array) => string;
  convertFromArrayBufferToHex: (arrayBuffer: Uint8Array) => string;
  convertFromArrayBufferToUTF8: (arrayBuffer: Uint8Array) => string;
  convertFromBase64ToArrayBuffer: (base64Str: string) => Uint8Array;
  convertFromBase64ToHex: (base64Str: string) => string;
  convertFromBase64ToUTF8: (base64Str: string) => string;
  convertFromHexToArrayBuffer: (hexStr: string) => Uint8Array;
  convertFromHexToBase64: (hexStr: string) => string;
  convertFromHexToUTF8: (hexStr: string) => string;
  convertFromUTF8ToArrayBuffer: (utf8Str: string) => Uint8Array;
  convertFromUTF8ToBase64: (utf8Str: string) => string;
  convertFromUTF8ToHex: (utf8Str: string) => string;
}
