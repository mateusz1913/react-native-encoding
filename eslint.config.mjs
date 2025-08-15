import callstackConfig from '@callstack/eslint-config/react-native.flat.js';
import { defineConfig } from '@eslint/config-helpers';
import eslintPluginRecommended from 'eslint-plugin-prettier/recommended';

export default defineConfig([
  callstackConfig,
  eslintPluginRecommended,
  {
    ignores: [
      // ignored files go here
      'dist/*',
      'lib/*',
      'native-tests/build/*',
    ],
  },
  {
    files: ['eslint.config.mjs'],
    rules: {
      'import/no-extraneous-dependencies': ['off'],
    },
  },
  {
    files: ['jest.config.js'],
    rules: {
      'import/no-extraneous-dependencies': ['off'],
    },
  },
  {
    files: ['**/*.ts', '**/*.tsx'],
    rules: {
      '@typescript-eslint/consistent-type-imports': 'error',
    },
  },
  {
    files: ['js-tests/**/*'],
    languageOptions: {
      globals: {
        jest: true,
      },
    },
  },
]);
