import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.WebElement;

public class TestRunner implements Runnable {
  private WebDriver _driver;

  public TestRunner(WebDriver wd) {
    _driver = wd;
  }

  public void run() {
    WebElement element = _driver.findElement(By.name("q"));
    element.sendKeys("Cheese!");
    element.submit();
    _driver.quit();
  }
}
