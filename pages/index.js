import Head from 'next/head';
import Header from '@components/Header';
import Footer from '@components/Footer';
import ImageGrid from '@components/ImageGrid';
import ImageUpload from '@components/ImageUpload';
import { useEffect, useState } from 'react';

export default function Home() {
  const [images, setImages] = useState([]);

  useEffect(() => {
    // Load images from local storage on component mount
    const savedImages = JSON.parse(localStorage.getItem('images')) || [];
    setImages(savedImages);
  }, []);

  const handleImageUpload = (url) => {
    const newImages = [...images, url];
    setImages(newImages);
    // Save to local storage
    localStorage.setItem('images', JSON.stringify(newImages));
  };

  return (
    <div className="container">
      <Head>
        <title>Your Dream Board App</title>
        <link rel="icon" href="/favicon.ico" />
      </Head>

      <Header title="Welcome to My Dream Board!" />
      <main>
        <ImageUpload onUpload={handleImageUpload} />
        <ImageGrid images={images} />
      </main>
      <Footer />
    </div>
  );
}
