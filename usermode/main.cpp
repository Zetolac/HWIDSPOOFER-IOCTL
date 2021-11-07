HANDLE driver_handle;
DWORD BytesReturned = 0;
#define ctl_spoof    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0366, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
int main() {
	driver_handle = CreateFileW((L"\\\\.\\YourFirstIoctlPastedSpoofer"), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (driver_handle == INVALID_HANDLE_VALUE) {
		system("cls"); printf("[+]LoadDriver/OpenAsAdmin\n"); system("pause"); exit(0);
	}
	std::cout << "Press Enter for Spoof";
	system("pause");
	DeviceIoControl(driver_handle, ctl_spoof, 0, 0, 0, 0, &BytesReturned, NULL);
}
