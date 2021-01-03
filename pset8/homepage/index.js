function toggleDarkMode() {
    const h = new Date().getHours();
    console.log(h)
    if (h < 8 || h >= 20) {
        document.body.classList.toggle("dark-mode");
        console.log("Switched to dark mode");
    }
}


// x.addEventListener("change", myFunction); // Attach listener function on state changes
document.onload = toggleDarkMode();