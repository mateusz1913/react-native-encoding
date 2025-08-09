import callstackConfig from '@callstack/eslint-config/react-native.flat.js';
import { defineConfig } from 'eslint/config';
import eslintPluginRecommended from 'eslint-plugin-prettier/recommended';

export default defineConfig([
  callstackConfig,
  eslintPluginRecommended,
  {
    ignores: [
      // ignored files go here
      'dist/*',
    ],
    rules: {
      // your custom rules
      '@typescript-eslint/consistent-type-imports': 'error',
    },
  },
  {
    files: ["js-tests/**/*"],
    languageOptions: {
      globals: {
        jest: true,
      },
    },
  },
]);
