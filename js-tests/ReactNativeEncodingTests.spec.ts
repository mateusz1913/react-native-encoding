import { ReactNativeEncoding } from '../src';

const dataset: Array<{ utf8: string; base64: string; hex: string }> = require('../tests-datasets/dataset.json');

describe('ReactNativeEncoding JS', () => {
  describe('base64 -> utf8', () => {
    it.each(dataset)('should decode base64 buffer to UTF8 string [$utf8]', ({ utf8, base64 }) => {
      expect(ReactNativeEncoding.convertFromBase64ToUTF8(base64)).toBe(utf8);
    });
  });

  describe('utf8 -> base64', () => {
    it.each(dataset)('should encode UTF8 string to base64 string [$utf8]', ({ utf8, base64 }) => {
      expect(ReactNativeEncoding.convertFromUTF8ToBase64(utf8)).toBe(base64);
    });
  });

  describe('hex -> utf8', () => {
    it.each(dataset)('should decode Hex string to UTF8 string [$utf8]', ({ utf8, hex }) => {
      expect(ReactNativeEncoding.convertFromHexToUTF8(hex)).toBe(utf8);
    });
  });

  describe('utf8 -> hex', () => {
    it.each(dataset)('should encode UTF8 string to hex string [$utf8]', ({ utf8, hex }) => {
      expect(ReactNativeEncoding.convertFromUTF8ToHex(utf8)).toBe(hex);
    });
  });
});
