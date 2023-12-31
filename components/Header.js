// components/Header.js
import Link from 'next/link';
import { useTheme } from '../context/ThemeContext';
import styles from '../styles/Header.module.css'; // Import the CSS module

export default function Header() {
  const { toggleTheme } = useTheme();

  return (
    <header className={styles.header}>
      <nav className={styles.nav}> {/* Add a local class */}
        <Link href="/">Home</Link> 
        <Link href="/about">About</Link>
        <Link href="/videos">Videos</Link>
      </nav>
      <button onClick={toggleTheme}>Toggle Theme</button>
    </header>
  );
}
