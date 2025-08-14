/**
 * @type {import('@react-native-community/cli-types').UserDependencyConfig}
 */
module.exports = {
  dependency: {
    platforms: {
      android: {
        cxxModuleCMakeListsModuleName: 'ReactNativeEncoding',
        cxxModuleCMakeListsPath: '../cpp/CMakeLists.txt',
        cxxModuleHeaderName: 'ReactNativeEncodingModule',
      },
    },
  },
};
