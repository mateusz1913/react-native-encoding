import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';
import type { UnsafeObject } from 'react-native/Libraries/Types/CodegenTypes';

interface Spec extends TurboModule {
  convertFromArrayBufferToBase64: (arrayBuffer: UnsafeObject) => string;
  convertFromArrayBufferToHex: (arrayBuffer: UnsafeObject) => string;
  convertFromArrayBufferToUTF8: (arrayBuffer: UnsafeObject) => string;
  convertFromBase64ToArrayBuffer: (base64Str: string) => UnsafeObject;
  convertFromBase64ToHex: (base64Str: string) => string;
  convertFromBase64ToUTF8: (base64Str: string) => string;
  convertFromHexToArrayBuffer: (hexStr: string) => UnsafeObject;
  convertFromHexToBase64: (hexStr: string) => string;
  convertFromHexToUTF8: (hexStr: string) => string;
  convertFromUTF8ToArrayBuffer: (utf8Str: string) => UnsafeObject;
  convertFromUTF8ToBase64: (utf8Str: string) => string;
  convertFromUTF8ToHex: (utf8Str: string) => string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('ReactNativeEncodingModule');
