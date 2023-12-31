// components/Footer.js
import styles from '../styles/Footer.module.css'; // Import the CSS module
s
export default function Footer() {
  return (
    <footer className={styles.footer}> {/* Use the styles object */}
      <p>Follow CodeKage on Social Media:</p>
      <div className={styles['social-links']}>
        <a href="https://instagram.com">Instagram</a>
        <a href="https://tiktok.com">TikTok</a>
        <a href="https://youtube.com">YouTube</a>
      </div>
    </footer>
  );
}
