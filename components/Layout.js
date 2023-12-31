// components/Layout.js
import Header from './Header';
import Footer from './Footer';
import { useTheme } from '../context/ThemeContext';
import styles from '../styles/Layout.module.css'; // Import the CSS module

export default function Layout({ children }) {
  const { theme } = useTheme();

  return (
    <div className={`${styles.layout} ${theme}`}> {/* Use the styles object */}
      <Header />
      <main className={styles.main}>{children}</main>
      <Footer />
    </div>
  );
}
