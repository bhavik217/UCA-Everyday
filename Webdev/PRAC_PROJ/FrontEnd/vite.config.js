// vite.config.js
import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  server: {
    proxy: {
      '/api': {
        target: 'http://localhost:8080',
        changeOrigin: true, // Ensures requests are handled as if from the target
        rewrite: (path) => path.replace(/^\/api/, ''), // Removes "/api" prefix when forwarding to backend
      },
    },
  },
  plugins: [react()],
});
