# `react-native-encoding`

Utilities for fast conversion between string, binary and hex representation of provided values using C++ turbo module

## Installation

```sh
npm install --save react-native-encoding
```

```sh
yarn add react-native-encoding
```

```sh
pnpm add react-native-encoding
```

```sh
bun add react-native-encoding
```

## Usage

```js
import { ReactNativeEncoding } from 'react-native-encoding';

// Convert utf-8 to base64 or hex strings and vice-versa
console.log(ReactNativeEncoding.convertFromUTF8ToBase64('Robert Kubica')); // outputs 'Um9iZXJ0IEt1YmljYQ=='
console.log(ReactNativeEncoding.convertFromUTF8ToHex('Robert Kubica')); // outputs '526f62657274204b7562696361'
console.log(ReactNativeEncoding.convertFromBase64ToUTF8('RmVybmFuZG8gQWxvbnNv')); // outputs 'Fernando Alonso'
console.log(ReactNativeEncoding.convertFromHexToUTF8('4d6178205665727374617070656e')); // outputs 'Max Verstappen'
console.log(ReactNativeEncoding.convertFromBase64ToHex('UmFuZHkgT3J0b24=')); // outputs '52616e6479204f72746f6e'
console.log(ReactNativeEncoding.convertFromHexToBase64('434d2050756e6b')); // outputs 'Q00gUHVuaw=='

// Convert to array buffer
const outputBuffer: Uint8Array = ReactNativeEncoding.convertFromBase64ToArrayBuffer('Q2hhcmxlcyBMZWNsZXJj')

// Convert from array buffer
function YEET(inputBuffer: Uint8Array) {
  return ReactNativeEncoding.convertFromArrayBufferToUTF8(inputBuffer);
}
```

## Expo

- ✅ You can use this library with [Development Builds](https://docs.expo.dev/development/introduction/).
- ❌ This library can't be used in the "Expo Go" app because it [requires custom native code](https://docs.expo.dev/workflow/customizing/).

## Acknowledgements

Base64 is implemented using https://github.com/tobiaslocker/base64 under MIT license

## Contributing

See the [contributing guide](./CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT
